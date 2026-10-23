"""chandah end to end: the notices, every layer and back, the two corrections, the refusal by name, Hindawi's keywords,
the manual's table read from the code, and (where Hindawi is here) revert and compile through Hindawi.
Plain Python, so the gate needs nothing installed: `python3 tests/test_chandah.py` (pytest also collects it).
© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI."""
import os, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DATA = ROOT / "tests" / "data"
ENV = dict(os.environ, PYTHONPATH=str(ROOT), PYTHONDONTWRITEBYTECODE="1")
NOTICE = "© 1993–2026 Abhishek Choudhary. All rights reserved."
sys.path.insert(0, str(ROOT))


class Skip(Exception):
    pass


def ch(*a, env=None):
    return subprocess.run([sys.executable, "-m", "chandah", *map(str, a)], capture_output=True, text=True,
                          env=env or ENV, cwd=ROOT)


def test_version_and_help_carry_the_notices():
    for args in (["--version"], ["--help"]):
        out = ch(*args).stdout
        assert NOTICE in out and "MIT" in out and "trademark" in out, out


def test_the_notebook_program_comes_back_through_every_layer():
    r = ch("stages", DATA / "binary_search.c")
    assert r.returncode == 0 and "8 of 8 layers come back exactly" in r.stdout, r.stdout[-600:]


def test_every_katapayadi_combination_comes_back():
    from chandah import core
    src = (DATA / "binary_search.c").read_text(encoding="utf-8")
    for structure in core.STRUCTURES:
        for sandhi in (False, True):
            if structure is None and sandhi:
                continue
            r = core.round_trip(src, "katapayadi", structure, sandhi)
            assert r["base_back"] and r["tree_back"], (structure, sandhi)


def test_comments_no_longer_stop_the_lexer():
    from chandah import core
    core.check("/* a comment */\n// a line comment\nपूर्णाङ्क मुख्यम्(शून्य) {\n  प्रत्यागम 0; // done\n}\n")


def test_a_program_outside_v11_is_refused_by_name():
    r = ch("stages", DATA / "bst.cpp")
    assert r.returncode == 2 and "refused: sutram v11 does not cover this program" in r.stdout, r.stdout[-400:]


def test_the_compile_check_never_simulates():
    env = {k: v for k, v in ENV.items() if k != "HINDAWI_HOME"}
    env["PATH"] = "/usr/bin:/bin"
    code = ("from sutram_tool import codec\ntry:\n    codec.ensure_compiles('x')\n    print('returned')\n"
            "except RuntimeError as e:\n    print('refused:', e)\n")
    r = subprocess.run([sys.executable, "-c", code], capture_output=True, text=True, env=env, cwd=ROOT)
    assert "refused: Hindawi is not here" in r.stdout, r.stdout + r.stderr


def test_hindawis_keywords_are_the_words_the_tool_uses():
    from sutram_tool.mappings import KEYWORDS, TYPES
    # Hindawi 2026.10's Sanskrit bindings of while, if, else, return, int and void (lang/hindawi/languages/sanskrit/c2h.uhin)
    assert KEYWORDS == {"यावत्", "यदि", "अन्यथा", "प्रत्यागम"} and TYPES == {"पूर्णाङ्क", "शून्य"}


def test_the_manual_table_is_read_from_the_code():
    from sutram_tool.mappings import OP_TO_SUTRAM
    manual = (ROOT / "docs" / "MANUAL.md").read_text(encoding="utf-8")
    missing = [k for k, v in OP_TO_SUTRAM.items() if f"| `{k.replace('|', chr(92) + '|')}` | {v} |" not in manual]
    assert not missing, missing


def test_the_word_list_reads_the_tables():
    r = ch("words")
    assert r.returncode == 0 and "योजय" in r.stdout and "प्रत्यागम" in r.stdout, r.stdout[-300:]


def test_revert_and_compile_through_hindawi():
    from chandah import core
    if core.hindawi_command() is None:
        raise Skip("Hindawi is not here")
    with tempfile.TemporaryDirectory() as d:
        r = ch("revert", DATA / "binary_search.c", "--out", Path(d) / "back.c")
        assert r.returncode == 0 and "same output: yes" in r.stdout, r.stdout[-800:]


if __name__ == "__main__":
    tests = [f for name, f in sorted(globals().items()) if name.startswith("test_") and callable(f)]
    failed = skipped = 0
    for f in tests:
        try:
            f(); print(f"   ok   {f.__name__}")
        except Skip as s:
            skipped += 1; print(f"   skip {f.__name__}: {s}")
        except AssertionError as e:
            failed += 1; print(f"   FAIL {f.__name__}: {str(e)[:400]}")
    print(f"{len(tests) - failed - skipped} of {len(tests)} tests passed" + (f", {skipped} skipped" if skipped else ""))
    sys.exit(1 if failed else 0)
