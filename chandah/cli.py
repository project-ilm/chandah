"""chandah: raise a Sanskrit C or C++ program, as Hindawi writes it, to chandah through the sutram layers, lower it back
to compilable Sanskrit C, and let Hindawi build and run it. © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI."""
import argparse, json, sys
from pathlib import Path

from . import NOTICE, __version__, core

EPILOG = """commands, each with --help:
  chandah raise prog.c                 to chandah: prog.c.chandah and its metadata prog.c.chandah.json
  chandah lower prog.c.chandah         back to compilable Sanskrit C: prog.lowered.c
  chandah run prog.c.chandah           lowered, then built and run by Hindawi (a .c or .cpp is run as it is)
  chandah check prog.c ...             every path there and back; Hindawi builds both and compares, where it is here
  chandah stages prog.c                every layer of one program
  chandah words                        the words chandah uses, read from its tables

exit codes: 0 done, 1 a check failed, 2 the input could not be read or used, 3 Hindawi is needed and is not here

""" + NOTICE


def _structure(value):
    return None if value in (None, "none") else value


def _read(path):
    try:
        return Path(path).read_text(encoding="utf-8")
    except (OSError, UnicodeDecodeError) as e:
        raise SystemExit(f"chandah: cannot read {path}: {e}")


def cmd_raise(a):
    src = _read(a.file)
    try:
        text, meta = core.raise_(src, a.numerals, _structure(a.structure), a.sandhi)
    except ValueError as e:
        print(f"chandah: {a.file}: {e}", file=sys.stderr); return 2
    out = Path(a.out or a.file + ".chandah")
    meta.update({"chandah": __version__, "source": Path(a.file).name, "suffix": Path(a.file).suffix or ".c"})
    out.write_text(text + "\n", encoding="utf-8")
    Path(str(out) + ".json").write_text(json.dumps(meta, ensure_ascii=False, indent=1), encoding="utf-8")
    print(f"raised {a.file} to {out} ({core.path_name(a.numerals, _structure(a.structure), a.sandhi)}); "
          f"metadata in {out}.json")
    return 0


def _load(chandah_path, meta_path=None):
    meta_file = Path(meta_path or str(chandah_path) + ".json")
    if not meta_file.exists():
        raise SystemExit(f"chandah: no metadata at {meta_file}; give it with --meta (raising writes it beside the text)")
    return _read(chandah_path).rstrip("\n"), json.loads(_read(meta_file))


def cmd_lower(a):
    text, meta = _load(a.file, a.meta)
    try:
        program = core.lower(text, meta)
    except Exception as e:
        print(f"chandah: {a.file} does not lower: {type(e).__name__}: {e}", file=sys.stderr); return 2
    stem = Path(a.file).name.removesuffix(".chandah")
    suffix = meta.get("suffix", ".c")
    out = Path(a.out or Path(a.file).with_name(Path(stem).stem + ".lowered" + suffix))
    out.write_text(program, encoding="utf-8")
    print(f"lowered {a.file} to {out}")
    return 0


def cmd_run(a):
    path = Path(a.file)
    if path.suffix == ".chandah":
        text, meta = _load(path, a.meta)
        program = core.lower(text, meta)
        path = path.with_name(Path(path.name.removesuffix(".chandah")).stem + ".lowered" + meta.get("suffix", ".c"))
        path.write_text(program, encoding="utf-8")
        print(f"(lowered to {path})", file=sys.stderr)
    if core.hindawi_command() is None:
        print("chandah: Hindawi is not here: install its tools (the notebook's Installation cell) or set HINDAWI_HOME",
              file=sys.stderr)
        return 3
    given = "" if a.input is None else (sys.stdin.read() if a.input == "-" else _read(a.input))
    code, output = core.hindawi_run(path, given)
    print(output, end="" if output.endswith("\n") else "\n")
    return code


def cmd_check(a):
    failed = 0
    for f in a.files:
        src = _read(f)
        try:
            lowered, report = core.check_paths(src)
        except ValueError as e:
            print(f"{f}: cannot be read: {e}"); failed += 1; continue
        bad = [(p, pr) for p, pr in report if pr]
        line = f"{f}: {len(report) - len(bad)} of {len(report)} paths there and back exactly"
        if a.compile is not False:
            res = core.compile_compare(src, lowered or "", Path(f).suffix or ".c")
            if res is None:
                if a.compile:
                    print("chandah: --compile needs Hindawi, which is not here", file=sys.stderr); return 3
                line += "; compile: Hindawi is not here, not run"
            else:
                same, ra, rb = res
                line += "; Hindawi builds both, same output" if same else f"; Hindawi: NOT the same (exit {ra[0]} and {rb[0]})"
                failed += not same
        print(line)
        for p, pr in bad:
            print(f"   {core.path_name(*p)}: {'; '.join(pr)}")
        failed += bool(bad)
    return 1 if failed else 0


def cmd_stages(a):
    try:
        text, code = core.stages_report(_read(a.file), a.file)
    except ValueError as e:
        print(f"chandah: {a.file}: {e}", file=sys.stderr); return 2
    print(text)
    return code


def cmd_words(a):
    from sutram_tool import mappings as m
    print("# tokens (v11's words, and the completion's)")
    for t, w in m.TOKEN_WORDS.items():
        print(f"{t}\t{w}")
    print("# inside strings, characters and header names")
    for c, w in m.LITERAL_WORDS.items():
        print(f"{c!r}\t{w}")
    for s, w in m.LITERAL_SEQUENCES:
        print(f"{s!r}\t{w}")
    print("# inside numbers")
    for c, w in m.NUMBER_CHAR_WORDS.items():
        print(f"{c!r}\t{w}")
    print("# keywords stay as Hindawi writes them; declarations are marked with " + m.WORD_PARIBHASHIT)
    return 0


def main(argv=None):
    p = argparse.ArgumentParser(prog="chandah", description="Raise Sanskrit C or C++, as Hindawi writes it, to chandah "
                                "through the sutram layers; lower it back to compilable Sanskrit C; build and run it "
                                "with Hindawi.", epilog=EPILOG, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--version", action="version", version=NOTICE)
    sub = p.add_subparsers(dest="cmd", required=True, metavar="command")
    r = sub.add_parser("raise", help="to chandah", description="Raise a program to chandah.")
    r.add_argument("file"); r.add_argument("-o", "--out", help="the chandah file (default: FILE.chandah)")
    r.add_argument("--numerals", choices=core.NUMERALS, default="katapayadi", help="default: katapayadi")
    r.add_argument("--structure", choices=["none"] + [s for s in core.STRUCTURES if s], default="none", help="default: none")
    r.add_argument("--sandhi", action="store_true", help="join words with sandhi, after the structure")
    lo = sub.add_parser("lower", help="back to compilable Sanskrit C", description="Lower a chandah file to Sanskrit C.")
    lo.add_argument("file"); lo.add_argument("-o", "--out"); lo.add_argument("--meta", help="default: FILE.json")
    ru = sub.add_parser("run", help="build and run with Hindawi", description="Build and run a program with Hindawi; "
                        "a .chandah file is lowered first.")
    ru.add_argument("file"); ru.add_argument("--meta")
    ru.add_argument("--input", help="a file whose text the program reads as its input ('-' for standard input)")
    c = sub.add_parser("check", help="every path there and back, and Hindawi's build", description="Check programs.")
    c.add_argument("files", nargs="+")
    g = c.add_mutually_exclusive_group()
    g.add_argument("--compile", dest="compile", action="store_true", default=None, help="require Hindawi's build")
    g.add_argument("--no-compile", dest="compile", action="store_false", help="check the paths only")
    s = sub.add_parser("stages", help="every layer of one program"); s.add_argument("file")
    sub.add_parser("words", help="the words chandah uses")
    a = p.parse_args(argv)
    return {"raise": cmd_raise, "lower": cmd_lower, "run": cmd_run, "check": cmd_check, "stages": cmd_stages,
            "words": cmd_words}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
