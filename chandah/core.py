"""chandah core: raise a Sanskrit C or C++ program, as Hindawi writes it, to chandah through the sutram layers; lower it
back to compilable Sanskrit C; check every path; and let Hindawi build and run it. One implementation, used by the
command line and the notebook IDE. © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI."""
import os, shutil, string, subprocess, sys, tempfile
from pathlib import Path

from sutram_tool import codec
from sutram_tool.lexer import lex_program
from sutram_tool.reverse import sutram_to_tokens

NUMERALS = list(codec.NUMERAL_CHOICES)
STRUCTURES = list(codec.STRUCTURE_CHOICES)
PATHS = [(n, s, d) for n in NUMERALS for s in STRUCTURES for d in (False, True) if not (s is None and d)]
LAYERS = [
    ("1 · base: a word for every token, Devanagari numerals", "devanagari", None, False),
    ("2 · numerals: katapayadi, wholly words", "katapayadi", None, False),
    ("3 · samasa, line by line, with sandhi", "katapayadi", "samasa_line", True),
    ("4 · samasa, the whole program, with sandhi", "katapayadi", "samasa_full", True),
    ("5 · chhandas: anushtubh, with sandhi", "katapayadi", "chhandas_anushtubh", True),
    ("6 · chhandas: gayatri, with sandhi", "katapayadi", "chhandas_gayatri", True),
    ("7 · chhandas: trishtubh, with sandhi", "katapayadi", "chhandas_trishtubh", True),
    ("8 · chhandas: jagati, with sandhi", "katapayadi", "chhandas_jagati", True),
]
SYMBOLS = set(string.punctuation)


def path_name(numerals, structure, sandhi):
    return f"{numerals}, {structure or 'no structure'}, sandhi {'on' if sandhi else 'off'}"


def raise_(src, numerals="katapayadi", structure=None, sandhi=False):
    """(chandah text, metadata). Raises ValueError, naming the line, for a character chandah cannot read."""
    return codec.encode(src, numeral_mode=numerals, structure=structure, apply_sandhi=sandhi)


def lower(text, meta):
    """Compilable Sanskrit C from a chandah text and the metadata its raising wrote."""
    return codec.decode(text, meta)[0]


def _tokens(src):
    return [[(k, t) for k, t, _ in line] for line in lex_program(src)]


def check_paths(src):
    """Every path: does the sutram come back exactly, is no symbol left, does every token come back, and does every
    path lower to the same program. Returns (lowered program, [(path, [problems])])."""
    want, lowered, report = _tokens(src), None, []
    for n, s, d in PATHS:
        problems = []
        try:
            text, meta = raise_(src, n, s, d)
            back, base = codec.decode(text, meta)
            if base != meta["base_sutram"]:
                problems.append("the sutram does not come back")
            left = sorted({c for c in text if c in SYMBOLS})
            if left:
                problems.append("symbols left: " + " ".join(left))
            got = [[("OP", t) if k == "GLUE" else (k, t) for k, t in line] for line in sutram_to_tokens(base)]
            if got != want:
                problems.append("the tokens do not come back")
            if lowered is None:
                lowered = back
            elif back != lowered:
                problems.append("lowers to a different program")
        except Exception as e:
            problems.append(f"{type(e).__name__}: {e}")
        report.append(((n, s, d), problems))
    return lowered, report


def hindawi_command():
    hin = shutil.which("hin")
    if hin:
        return [hin]
    home = os.environ.get("HINDAWI_HOME", "")
    if home and os.path.exists(os.path.join(home, "bin", "hin")):
        return [sys.executable, os.path.join(home, "bin", "hin")]
    return None


def hindawi_run(path, given="", lang="sanskrit"):
    """(exit code, output) of Hindawi building and running the program, or None when Hindawi is not here."""
    cmd = hindawi_command()
    if cmd is None:
        return None
    r = subprocess.run(cmd + ["run", lang, str(path)], input=given, capture_output=True, text=True, timeout=600)
    return r.returncode, (r.stdout if r.returncode == 0 else (r.stdout + r.stderr))


def compile_compare(src, lowered, suffix=".c", given=""):
    """Hindawi builds and runs the original and the lowered program; (same?, original result, lowered result), or None."""
    if hindawi_command() is None:
        return None
    with tempfile.TemporaryDirectory() as d:
        a, b = Path(d) / ("original" + suffix), Path(d) / ("lowered" + suffix)
        a.write_text(src, encoding="utf-8"); b.write_text(lowered, encoding="utf-8")
        ra, rb = hindawi_run(a, given), hindawi_run(b, given)
    return (ra[0] == 0 and ra == rb), ra, rb


def stages_report(src, name="the program"):
    lines, bad = [f"── {name}", src.rstrip()], 0
    for title, n, s, d in LAYERS:
        text, meta = raise_(src, n, s, d)
        back, base = codec.decode(text, meta)
        ok = base == meta["base_sutram"]
        bad += not ok
        lines += ["", f"── {title}   (comes back exactly: {'yes' if ok else 'NO'})", text.rstrip()]
    lines += ["", f"{len(LAYERS) - bad} of {len(LAYERS)} layers come back exactly"]
    return "\n".join(lines), (1 if bad else 0)
