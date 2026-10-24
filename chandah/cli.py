"""chandah: raise a C or C++ program, in any language Hindawi supports, to chandah through the sutram layers; lower it
back to compilable form; build and run it with Hindawi, one program or a whole project.
© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI."""
import argparse, json, subprocess, sys, tempfile
from pathlib import Path

from . import NOTICE, __version__, core

EPILOG = """commands, each with --help:
  chandah raise prog.c                       to chandah: prog.c.chandah and its metadata prog.c.chandah.json
  chandah lower prog.c.chandah               back to compilable form: prog.lowered.c
  chandah run prog.c.chandah                 lowered, then built and run by Hindawi (a .c or .cpp runs as it is)
  chandah check prog.c ...                   every path there and back; Hindawi builds both, where it is here
  chandah stages prog.c                      every layer of one program
  chandah cc --lang L [gcc arguments]        gcc for chandah sources, like hindawicc: each .chandah is lowered first
  chandah build TREE --lang L [-- make ...]  a project of chandah sources, built with its own make through hindawicc
  chandah raise-tree SRC OUT                 every C and C++ file of a project to chandah, beside the rest
  chandah lower-tree TREE OUT                and back
  chandah words                              the words chandah uses, read from its tables
--lang is the program's language (default sanskrit): any language Hindawi supports.

exit codes: 0 done, 1 a check failed, 2 the input could not be read or used, 3 Hindawi is needed and is not here

""" + NOTICE


def _structure(value):
    return None if value in (None, "none") else value


def _read(path):
    try:
        return Path(path).read_text(encoding="utf-8")
    except (OSError, UnicodeDecodeError) as e:
        raise SystemExit(f"chandah: cannot read {path}: {e}")


def _no_hindawi(what="hin"):
    print(f"chandah: Hindawi is not here ({what}): install its tools (the notebook's Installation cell) or set "
          "HINDAWI_HOME", file=sys.stderr)
    return 3


def cmd_raise(a):
    try:
        text, meta = core.raise_(_read(a.file), a.numerals, _structure(a.structure), a.sandhi, a.lang)
    except ValueError as e:
        print(f"chandah: {a.file}: {e}", file=sys.stderr); return 2
    out = Path(a.out or a.file + ".chandah")
    meta.update({"chandah": __version__, "source": Path(a.file).name, "suffix": Path(a.file).suffix or ".c"})
    out.write_text(text + "\n", encoding="utf-8")
    Path(str(out) + ".json").write_text(json.dumps(meta, ensure_ascii=False, indent=1), encoding="utf-8")
    print(f"raised {a.file} to {out} ({a.lang}; {core.path_name(a.numerals, _structure(a.structure), a.sandhi)}); "
          f"metadata in {out}.json")
    return 0


def _load(chandah_path, meta_path=None):
    meta_file = Path(meta_path or str(chandah_path) + ".json")
    meta = json.loads(_read(meta_file)) if meta_file.exists() else None
    return _read(chandah_path).rstrip("\n"), meta


def _lowered_name(path, meta):
    stem = Path(path).name.removesuffix(".chandah")
    suffix = (meta or {}).get("suffix") or Path(stem).suffix or ".c"
    return Path(path).with_name(Path(stem).stem + ".lowered" + suffix)


def cmd_lower(a):
    text, meta = _load(a.file, a.meta)
    try:
        program = core.lower(text, meta)
    except Exception as e:
        print(f"chandah: {a.file} does not lower: {type(e).__name__}: {e} (a layered file needs its metadata, "
              "FILE.json, written when it was raised)", file=sys.stderr)
        return 2
    out = Path(a.out or _lowered_name(a.file, meta))
    out.write_text(program, encoding="utf-8")
    print(f"lowered {a.file} to {out}")
    return 0


def cmd_run(a):
    path, lang = Path(a.file), a.lang
    if path.suffix == ".chandah":
        text, meta = _load(path, a.meta)
        lang = (meta or {}).get("lang", lang)
        out = _lowered_name(path, meta)
        out.write_text(core.lower(text, meta), encoding="utf-8")
        print(f"(lowered to {out})", file=sys.stderr)
        path = out
    if core.hindawi_command() is None:
        return _no_hindawi()
    given = "" if a.input is None else (sys.stdin.read() if a.input == "-" else _read(a.input))
    code, output = core.hindawi_run(path, given, lang)
    print(output, end="" if output.endswith("\n") else "\n")
    return code


def cmd_check(a):
    failed = 0
    for f in a.files:
        src = _read(f)
        try:
            lowered, report = core.check_paths(src, a.lang)
        except ValueError as e:
            print(f"{f}: cannot be read: {e}"); failed += 1; continue
        bad = [(p, pr) for p, pr in report if pr]
        line = f"{f}: {len(report) - len(bad)} of {len(report)} paths there and back exactly"
        if a.compile is not False:
            res = core.compile_compare(src, lowered or "", Path(f).suffix or ".c", lang=a.lang)
            if res is None:
                if a.compile:
                    return _no_hindawi()
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
        text, code = core.stages_report(_read(a.file), a.file, a.lang)
    except ValueError as e:
        print(f"chandah: {a.file}: {e}", file=sys.stderr); return 2
    print(text)
    return code


def cmd_cc(a, rest):
    """gcc for chandah sources, as hindawicc is for native ones: each NAME.chandah argument is lowered to NAME in a
    working folder, and the arguments go to Hindawi's own driver (hindawi cc --lang L)."""
    tool = core.hindawi_tool("hindawi")
    if tool is None:
        return _no_hindawi("hindawi cc")
    work = Path(tempfile.mkdtemp(prefix="chandah-cc-"))
    args = []
    for arg in rest:
        if arg.endswith(".chandah") and Path(arg).is_file():
            text, meta = _load(arg)
            out = work / Path(arg).name.removesuffix(".chandah")
            out.write_text(core.lower(text, meta), encoding="utf-8")
            args.append(str(out))
        else:
            args.append(arg)
    return subprocess.run(tool + ["cc", "--lang", a.lang] + args).returncode


def cmd_build(a, rest):
    """A project of chandah sources built with its own make: the tree is lowered into a working tree, and Hindawi
    builds that through hindawicc (hindawi build TREE --lang L -- make arguments)."""
    tool = core.hindawi_tool("hindawi")
    if tool is None:
        return _no_hindawi("hindawi build")
    work = Path(a.work or tempfile.mkdtemp(prefix="chandah-build-")) / Path(a.tree).resolve().name
    n = core.lower_tree(a.tree, work)
    print(f"lowered {n} chandah files into {work}")
    if a.lower_only:
        return 0
    make = rest[1:] if rest[:1] == ["--"] else rest
    return subprocess.run(tool + ["build", str(work), "--lang", a.lang] + (["--"] + make if make else [])).returncode


def cmd_raise_tree(a):
    done, kept = core.raise_tree(a.src, a.out, a.lang, a.numerals)
    print(f"raised {len(done)} C and C++ files of {a.src} to chandah in {a.out}; {len(kept)} kept as they were "
          f"(listed with the reason in {a.out}/.chandah/manifest.json)")
    return 0


def cmd_lower_tree(a):
    n = core.lower_tree(a.tree, a.out)
    print(f"lowered {n} chandah files of {a.tree} into {a.out}")
    return 0


def cmd_words(a):
    from sutram_tool import mappings as m
    print("# tokens")
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
    print("# keywords and names stay as the language writes them; declarations are marked " + m.WORD_PARIBHASHIT)
    return 0


def main(argv=None):
    argv = list(sys.argv[1:] if argv is None else argv)
    p = argparse.ArgumentParser(prog="chandah", description="Raise C or C++, in any language Hindawi supports, to "
                                "chandah through the sutram layers; lower it back to compilable form; build and run "
                                "it with Hindawi.", epilog=EPILOG, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--version", action="version", version=NOTICE)
    sub = p.add_subparsers(dest="cmd", required=True, metavar="command")

    def lang(q):
        q.add_argument("--lang", default="sanskrit", help="the program's language (default sanskrit)")

    r = sub.add_parser("raise", help="to chandah", description="Raise a program to chandah.")
    r.add_argument("file"); r.add_argument("-o", "--out", help="the chandah file (default: FILE.chandah)"); lang(r)
    r.add_argument("--numerals", choices=core.NUMERALS, default="katapayadi", help="default: katapayadi")
    r.add_argument("--structure", choices=["none"] + [s for s in core.STRUCTURES if s], default="none", help="default: none")
    r.add_argument("--sandhi", action="store_true", help="join words with sandhi, after the structure")
    lo = sub.add_parser("lower", help="back to compilable form", description="Lower a chandah file.")
    lo.add_argument("file"); lo.add_argument("-o", "--out"); lo.add_argument("--meta", help="default: FILE.json")
    ru = sub.add_parser("run", help="build and run with Hindawi", description="Build and run a program with Hindawi; "
                        "a .chandah file is lowered first.")
    ru.add_argument("file"); ru.add_argument("--meta"); lang(ru)
    ru.add_argument("--input", help="a file whose text the program reads as its input ('-' for standard input)")
    c = sub.add_parser("check", help="every path there and back, and Hindawi's build", description="Check programs.")
    c.add_argument("files", nargs="+"); lang(c)
    g = c.add_mutually_exclusive_group()
    g.add_argument("--compile", dest="compile", action="store_true", default=None, help="require Hindawi's build")
    g.add_argument("--no-compile", dest="compile", action="store_false", help="check the paths only")
    s = sub.add_parser("stages", help="every layer of one program"); s.add_argument("file"); lang(s)
    cc = sub.add_parser("cc", help="gcc for chandah sources, like hindawicc", add_help=False)
    lang(cc)
    b = sub.add_parser("build", help="build a project of chandah sources", description="Build a project of chandah "
                       "sources with its own make, through hindawicc. Arguments after -- go to make.")
    b.add_argument("tree"); lang(b); b.add_argument("--work", help="where the lowered tree is built")
    b.add_argument("--lower-only", action="store_true", help="lower the tree and stop")
    rt = sub.add_parser("raise-tree", help="a project's C and C++ files to chandah")
    rt.add_argument("src"); rt.add_argument("out"); lang(rt)
    rt.add_argument("--numerals", choices=core.NUMERALS, default="katapayadi")
    lt = sub.add_parser("lower-tree", help="a chandah project back"); lt.add_argument("tree"); lt.add_argument("out")
    sub.add_parser("words", help="the words chandah uses")
    if argv[:1] == ["cc"]:
        a, rest = p.parse_known_args(argv[:1] + [x for x in argv[1:3] if x.startswith("--lang")] +
                                     ([argv[2]] if argv[1:2] == ["--lang"] else []))
        skip = 2 if argv[1:2] == ["--lang"] else (1 if argv[1:2] and argv[1].startswith("--lang=") else 0)
        return cmd_cc(a, argv[1 + skip:])
    if argv[:1] == ["build"] and "--" in argv:
        k = argv.index("--")
        a = p.parse_args(argv[:k])
        return cmd_build(a, argv[k:])
    a = p.parse_args(argv)
    if a.cmd == "build":
        return cmd_build(a, [])
    return {"raise": cmd_raise, "lower": cmd_lower, "run": cmd_run, "check": cmd_check, "stages": cmd_stages,
            "raise-tree": cmd_raise_tree, "lower-tree": cmd_lower_tree, "words": cmd_words}[a.cmd](a)


if __name__ == "__main__":
    sys.exit(main())
