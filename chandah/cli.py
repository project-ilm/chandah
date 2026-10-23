"""chandah: take a Sanskrit C program, as Hindawi writes it, through the sutram layers to chandas and back, then let
Hindawi build and run both and compare. © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI."""
import argparse, json, sys
from pathlib import Path

from . import NOTICE, core


def _layer_options(q):
    q.add_argument("--numerals", choices=core.NUMERALS, default="katapayadi")
    q.add_argument("--structure", choices=[s for s in core.STRUCTURES if s] + ["none"], default="chhandas_anushtubh")
    q.add_argument("--no-sandhi", dest="sandhi", action="store_false")


def _structure(a):
    return None if a.structure == "none" else a.structure


def main(argv=None):
    p = argparse.ArgumentParser(prog="chandah", description="Sanskrit C, as Hindawi writes it, through the sutram layers to "
                                "chandas and back, built and run by Hindawi.", epilog=NOTICE,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--version", action="version", version=NOTICE)
    sub = p.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("stages", help="every layer of a program, each checked on the way back")
    s.add_argument("file")
    r = sub.add_parser("revert", help="to chandah and back, then built and run by Hindawi, original and reverted compared")
    r.add_argument("file"); _layer_options(r); r.add_argument("--out")
    e = sub.add_parser("encode", help="write the chandah text and its metadata")
    e.add_argument("file"); _layer_options(e); e.add_argument("-o", "--out", required=True)
    d = sub.add_parser("decode", help="from a chandah text and its metadata back to Sanskrit C")
    d.add_argument("file"); d.add_argument("--meta", required=True); d.add_argument("-o", "--out", required=True)
    sub.add_parser("words", help="the words v11 uses, read from its own tables")
    a = p.parse_args(argv)

    if a.cmd == "stages":
        text, code = core.stages_report(Path(a.file).read_text(encoding="utf-8"), a.file)
        print(text); return code
    if a.cmd == "revert":
        text, code = core.revert_report(a.file, a.numerals, _structure(a), a.sandhi, a.out)
        print(text); return code
    if a.cmd == "encode":
        try:
            core.check(Path(a.file).read_text(encoding="utf-8"))
        except core.NotCovered as err:
            print(f"refused: {err}"); return 2
        from sutram_tool import codec
        text, meta = codec.encode(Path(a.file).read_text(encoding="utf-8"), numeral_mode=a.numerals,
                                  structure=_structure(a), apply_sandhi=a.sandhi)
        Path(a.out).write_text(text, encoding="utf-8")
        Path(a.out + ".meta.json").write_text(json.dumps(meta, ensure_ascii=False, indent=1), encoding="utf-8")
        print(f"wrote {a.out} and {a.out}.meta.json"); return 0
    if a.cmd == "decode":
        from sutram_tool import codec
        back, _ = codec.decode(Path(a.file).read_text(encoding="utf-8"), json.loads(Path(a.meta).read_text(encoding="utf-8")))
        Path(a.out).write_text(back, encoding="utf-8"); print(f"wrote {a.out}"); return 0
    if a.cmd == "words":
        from sutram_tool import mappings as m
        print("# operators"); [print(f"{k}\t{v}") for k, v in m.OP_TO_SUTRAM.items()]
        print("# keywords and types (Hindawi's Sanskrit bindings, kept as written)"); [print(w) for w in sorted(m.KEYWORDS | m.TYPES)]
        print("# headers"); [print(f"{k}\t{' '.join(v)}") for k, v in m.HEADER_MAP.items()]
        print("# formats"); [print(f"{k}\t{v}") for k, v in m.FORMAT_MAP.items()]
        return 0
    return 2


if __name__ == "__main__":
    sys.exit(main())
