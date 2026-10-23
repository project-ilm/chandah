"""chandah core: a Sanskrit C program, as Hindawi writes it, through the sutram layers and back, every layer checked on
the way back, and Hindawi to build and run it. One implementation, used by the command line and the notebook panel.
© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI."""
import os, shutil, subprocess, sys
from pathlib import Path

from sutram_tool import codec
from sutram_tool.parser import parse_source

NUMERALS = list(codec.NUMERAL_CHOICES)
STRUCTURES = list(codec.STRUCTURE_CHOICES)
# The layers `stages` shows, in order. From the second layer on the numerals are katapayadi: in v11 that is the numeral
# mode that comes back through every structure (docs/MANUAL.md, Measured).
LAYERS = [
    ("1 · base: words, Devanagari numerals", "devanagari", None, False),
    ("2 · numerals: katapayadi, wholly words", "katapayadi", None, False),
    ("3 · samasa, line by line, with sandhi", "katapayadi", "samasa_line", True),
    ("4 · samasa, the whole program, with sandhi", "katapayadi", "samasa_full", True),
    ("5 · chhandas: anushtubh, with sandhi", "katapayadi", "chhandas_anushtubh", True),
    ("6 · chhandas: gayatri, with sandhi", "katapayadi", "chhandas_gayatri", True),
    ("7 · chhandas: trishtubh, with sandhi", "katapayadi", "chhandas_trishtubh", True),
    ("8 · chhandas: jagati, with sandhi", "katapayadi", "chhandas_jagati", True),
]


class NotCovered(Exception):
    """The program uses something sutram v11 does not cover: it is refused by name, never half-converted."""


def check(src):
    try:
        return parse_source(src)
    except Exception as e:
        reason = (str(e).splitlines() or [type(e).__name__])[0] or type(e).__name__
        raise NotCovered(f"sutram v11 does not cover this program (its parser stopped at: {reason})") from None


def round_trip(src, numerals="katapayadi", structure="chhandas_anushtubh", sandhi=True):
    tree = check(src)
    text, meta = codec.encode(src, numeral_mode=numerals, structure=structure, apply_sandhi=sandhi)
    back, base = codec.decode(text, meta)
    try:
        tree_back = parse_source(back) == tree
    except Exception:
        tree_back = False
    return {"text": text, "meta": meta, "reverted": back, "base_back": base == meta["base_sutram"], "tree_back": tree_back}


def hindawi_command():
    hin = shutil.which("hin")
    if hin:
        return [hin]
    home = os.environ.get("HINDAWI_HOME", "")
    if home and os.path.exists(os.path.join(home, "bin", "hin")):
        return [sys.executable, os.path.join(home, "bin", "hin")]
    return None


def hindawi_run(path, lang="sanskrit"):
    """(exit code, output) of Hindawi building and running the program, or None when Hindawi is not here."""
    cmd = hindawi_command()
    if cmd is None:
        return None
    r = subprocess.run(cmd + ["run", lang, str(path)], stdin=subprocess.DEVNULL, capture_output=True, text=True, timeout=600)
    return r.returncode, (r.stdout if r.returncode == 0 else (r.stdout + r.stderr))


def stages_report(src, name="the program"):
    lines = [f"── {name}", src.rstrip()]
    try:
        check(src)
    except NotCovered as e:
        return "\n".join(lines + ["", f"refused: {e}", "What v11 covers: docs/MANUAL.md, Coverage."]), 2
    bad = 0
    for title, numerals, structure, sandhi in LAYERS:
        r = round_trip(src, numerals, structure, sandhi)
        ok = r["base_back"] and r["tree_back"]
        bad += not ok
        lines += ["", f"── {title}   (comes back exactly: {'yes' if ok else 'NO'})", r["text"].rstrip()]
    lines += ["", f"{len(LAYERS) - bad} of {len(LAYERS)} layers come back exactly"]
    return "\n".join(lines), (1 if bad else 0)


def revert_report(path, numerals="katapayadi", structure="chhandas_anushtubh", sandhi=True, out=None):
    path = Path(path)
    src = path.read_text(encoding="utf-8")
    try:
        r = round_trip(src, numerals, structure, sandhi)
    except NotCovered as e:
        return f"refused: {e}", 2
    out = Path(out) if out else path.with_name(path.stem + ".reverted" + path.suffix)
    out.write_text(r["reverted"], encoding="utf-8")
    lines = [f"── {path.name}: to chandah ({numerals} numerals, {structure or 'no structure'}, sandhi {'on' if sandhi else 'off'}) and back",
             f"   the base sutram came back exactly: {'yes' if r['base_back'] else 'NO'}",
             f"   the program's parse tree came back exactly: {'yes' if r['tree_back'] else 'NO'}",
             f"   the reverted program: {out}", "", r["reverted"].rstrip()]
    layers_ok = r["base_back"] and r["tree_back"]
    first = hindawi_run(path)
    if first is None:
        lines += ["", "compile and run: Hindawi is not here (the notebook's Installation cell, or HINDAWI_HOME); not run"]
        return "\n".join(lines), (0 if layers_ok else 1)
    second = hindawi_run(out)
    same = first[0] == 0 and second[0] == 0 and first[1] == second[1]
    lines += ["", f"── the original, built and run by Hindawi (exit {first[0]}):", first[1].rstrip(),
              f"── the reverted program, built and run by Hindawi (exit {second[0]}):", second[1].rstrip(),
              "", f"same output: {'yes' if same else 'NO'}"]
    return "\n".join(lines), (0 if (same and layers_ok) else 1)
