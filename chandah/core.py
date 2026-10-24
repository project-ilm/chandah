"""chandah core: raise a C or C++ program, in any language Hindawi supports, to chandah through the sutram layers; lower
it back to compilable form; check every path; build and run it with Hindawi; and do the same for a whole tree. One
implementation, used by the command line and the notebook IDE. © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI."""
import json, os, shutil, string, subprocess, sys, tempfile
from pathlib import Path

from sutram_tool import codec
from sutram_tool.lexer import lex_program
from sutram_tool.reverse import sutram_to_tokens, sutram_to_source

NUMERALS = list(codec.NUMERAL_CHOICES)
STRUCTURES = list(codec.STRUCTURE_CHOICES)
PATHS = [(n, s, d) for n in NUMERALS for s in STRUCTURES for d in (False, True) if not (s is None and d)]
LAYERS = [
    ("1 · base: a word for every symbol, Devanagari numerals", "devanagari", None, False),
    ("2 · numerals: katapayadi, wholly words", "katapayadi", None, False),
    ("3 · samasa, line by line, with sandhi", "katapayadi", "samasa_line", True),
    ("4 · samasa, the whole program, with sandhi", "katapayadi", "samasa_full", True),
    ("5 · chhandas: anushtubh, with sandhi", "katapayadi", "chhandas_anushtubh", True),
    ("6 · chhandas: gayatri, with sandhi", "katapayadi", "chhandas_gayatri", True),
    ("7 · chhandas: trishtubh, with sandhi", "katapayadi", "chhandas_trishtubh", True),
    ("8 · chhandas: jagati, with sandhi", "katapayadi", "chhandas_jagati", True),
]
SYMBOLS = set(string.punctuation)
SOURCES = {".c", ".h", ".cc", ".cpp", ".cxx", ".hpp", ".hh"}
LANGUAGES = json.loads((Path(__file__).parent / "languages.json").read_text(encoding="utf-8"))


def profile(lang):
    """The language's own declaration and control keywords, from Hindawi's tables; English needs none."""
    p = LANGUAGES.get(lang, {})
    return {"declaration_starters": p.get("declaration_starters", []) if lang != "english" else ["int", "char", "void", "float", "double", "long", "short", "unsigned", "signed", "struct", "union", "enum", "const", "static", "extern", "typedef", "bool", "class", "template", "typename"],
            "operand_breakers": p.get("operand_breakers", []) if lang != "english" else ["return", "sizeof", "case", "else", "do", "if", "while", "for", "switch", "new", "delete"]}


def path_name(numerals, structure, sandhi):
    return f"{numerals}, {structure or 'no structure'}, sandhi {'on' if sandhi else 'off'}"


def raise_(src, numerals="katapayadi", structure=None, sandhi=False, lang="sanskrit"):
    """(chandah text, metadata). Raises ValueError, naming the line, for a character chandah cannot read."""
    text, meta = codec.encode(src, numeral_mode=numerals, structure=structure, apply_sandhi=sandhi, **profile(lang))
    meta["lang"] = lang
    return text, meta


def lower(text, meta=None):
    """The compilable program from a chandah text: the base layer needs nothing else; the other layers need the
    metadata their raising wrote."""
    if not meta or meta.get("structure") is None:
        return sutram_to_source(text)
    return codec.decode(text, meta)[0]


def tokens(src):
    return [[(k, t) for k, t, _ in line] for line in lex_program(src)]


def check_paths(src, lang="sanskrit"):
    """Every path: the sutram comes back exactly, no symbol is left, every token comes back, every path lowers to the
    same program. Returns (lowered program, [(path, [problems])])."""
    want, lowered, report = tokens(src), None, []
    for n, s, d in PATHS:
        problems = []
        try:
            text, meta = raise_(src, n, s, d, lang)
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


def _tool(name):
    found = shutil.which(name)
    if found:
        return [found]
    home = os.environ.get("HINDAWI_HOME", "")
    if home and os.path.exists(os.path.join(home, "bin", name)):
        return [sys.executable, os.path.join(home, "bin", name)]
    return None


def hindawi_command():
    return _tool("hin")


def hindawi_run(path, given="", lang="sanskrit"):
    """(exit code, output) of Hindawi building and running the program, or None when Hindawi is not here."""
    cmd = hindawi_command()
    if cmd is None:
        return None
    r = subprocess.run(cmd + ["run", lang, str(path)], input=given, capture_output=True, text=True, timeout=600)
    return r.returncode, (r.stdout if r.returncode == 0 else (r.stdout + r.stderr))


def compile_compare(src, lowered, suffix=".c", given="", lang="sanskrit"):
    """Hindawi builds and runs the original and the lowered program; (same?, original result, lowered result), or None."""
    if hindawi_command() is None:
        return None
    with tempfile.TemporaryDirectory() as d:
        a, b = Path(d) / ("original" + suffix), Path(d) / ("lowered" + suffix)
        a.write_text(src, encoding="utf-8"); b.write_text(lowered, encoding="utf-8")
        ra, rb = hindawi_run(a, given, lang), hindawi_run(b, given, lang)
    return (ra[0] == 0 and ra == rb), ra, rb


def stages_report(src, name="the program", lang="sanskrit"):
    lines, bad = [f"── {name}", src.rstrip()], 0
    for title, n, s, d in LAYERS:
        text, meta = raise_(src, n, s, d, lang)
        back, base = codec.decode(text, meta)
        ok = base == meta["base_sutram"]
        bad += not ok
        lines += ["", f"── {title}   (comes back exactly: {'yes' if ok else 'NO'})", text.rstrip()]
    lines += ["", f"{len(LAYERS) - bad} of {len(LAYERS)} layers come back exactly"]
    return "\n".join(lines), (1 if bad else 0)


def raise_tree(src_tree, out_tree, lang="sanskrit", numerals="katapayadi"):
    """Every C and C++ source and header of a tree raised to chandah's base layer, as NAME.chandah beside the rest of
    the tree, which is copied as it is. Returns (converted, kept as they were with the reason)."""
    src_tree, out_tree = Path(src_tree), Path(out_tree)
    if out_tree.exists():
        shutil.rmtree(out_tree)
    shutil.copytree(src_tree, out_tree, symlinks=True, ignore=shutil.ignore_patterns(".git"))
    done, kept = [], []
    for f in sorted(p for p in out_tree.rglob("*") if p.is_file() and not p.is_symlink() and p.suffix in SOURCES):
        rel = str(f.relative_to(out_tree))
        try:
            src = f.read_text(encoding="utf-8")
            text, _ = raise_(src, numerals, None, False, lang)
            if tokens(sutram_to_source(text)) != tokens(src):
                raise ValueError("does not come back exactly")
        except (ValueError, UnicodeDecodeError) as e:
            kept.append((rel, str(e)[:120])); continue
        Path(str(f) + ".chandah").write_text(text + "\n", encoding="utf-8")
        f.unlink(); done.append(rel)
    meta = {"chandah": __import__("chandah").__version__, "lang": lang, "numerals": numerals, "converted": done,
            "kept": [{"file": k, "why": w} for k, w in kept]}
    (out_tree / ".chandah").mkdir(exist_ok=True)
    (out_tree / ".chandah" / "manifest.json").write_text(json.dumps(meta, ensure_ascii=False, indent=1), encoding="utf-8")
    return done, kept


def lower_tree(tree, out_tree):
    """Every NAME.chandah of a tree lowered back to NAME, the rest copied as it is."""
    tree, out_tree = Path(tree), Path(out_tree)
    if out_tree.exists():
        shutil.rmtree(out_tree)
    shutil.copytree(tree, out_tree, symlinks=True, ignore=shutil.ignore_patterns(".git"))
    n = 0
    for f in sorted(p for p in out_tree.rglob("*.chandah") if p.is_file()):
        Path(str(f)[:-len(".chandah")]).write_text(sutram_to_source(f.read_text(encoding="utf-8").rstrip("\n")), encoding="utf-8")
        f.unlink(); n += 1
    return n


def hindawi_tool(name="hindawi"):
    return _tool(name)
