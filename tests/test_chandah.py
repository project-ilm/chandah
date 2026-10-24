"""chandah end to end: the notices; Meta's acceptance test and minimal example; every sample through every path and back;
the command line; the two corrections; Hindawi's keywords; the manual's tables read from the code; and, where Hindawi is
here, every sample built and run by Hindawi, original and lowered, with the same output.
Plain Python, so the gate needs nothing installed: `python3 tests/test_chandah.py` (pytest also collects it).
© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI."""
import concurrent.futures as cf, os, shutil, subprocess, sys, tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SAMPLES = sorted(ROOT.glob("samples/**/*.c")) + sorted(ROOT.glob("samples/**/*.cpp"))
ENV = dict(os.environ, PYTHONPATH=str(ROOT), PYTHONDONTWRITEBYTECODE="1")
NOTICE = "© 1993–2026 Abhishek Choudhary. All rights reserved."
sys.path.insert(0, str(ROOT))


class Skip(Exception):
    pass


def ch(*a, env=None, cwd=None):
    return subprocess.run([sys.executable, "-m", "chandah", *map(str, a)], capture_output=True, text=True,
                          env=env or ENV, cwd=cwd or ROOT, stdin=subprocess.DEVNULL)


def test_version_and_help_carry_the_notices():
    for args in (["--version"], ["--help"]):
        out = ch(*args).stdout
        assert NOTICE in out and "MIT" in out and "trademark" in out, out


def test_metas_acceptance_test():
    code = ("from sutram_tool import codec\n"
            "src=open('example_src.txt',encoding='utf-8').read()\n"
            "enc,meta=codec.encode(src,numeral_mode='katapayadi',structure=None,apply_sandhi=False)\n"
            "assert all(c not in enc for c in '{}();'), 'symbols remain'\n"
            "dec_c,dec_s=codec.decode(enc,meta)\n"
            "assert dec_s==meta['base_sutram'], 'sutram not bijective'\n"
            "print('PASS')\n")
    r = subprocess.run([sys.executable, "-c", code], capture_output=True, text=True, env=ENV, cwd=ROOT)
    assert r.stdout.strip() == "PASS", r.stdout + r.stderr


def test_metas_minimal_example():
    from sutram_tool import codec
    enc, meta = codec.encode("पूर्णाङ्क मुख्य() { पूर्णाङ्क अ = 1; }", numeral_mode="katapayadi", structure=None, apply_sandhi=False)
    dec_c, dec_s = codec.decode(enc, meta)
    assert dec_s == meta["base_sutram"] and not any(c in enc for c in "{}();"), enc


def test_every_sample_through_every_path_and_back():
    from chandah import core
    assert len(SAMPLES) == 116, len(SAMPLES)
    failures = []
    for f in SAMPLES:
        _, report = core.check_paths(f.read_text(encoding="utf-8"))
        failures += [(f.name, core.path_name(*p), pr) for p, pr in report if pr]
    assert not failures, failures[:5]


def test_the_command_line_raises_and_lowers():
    from chandah import core
    with tempfile.TemporaryDirectory() as d:
        for name in ("binary_search.c", "bst.cpp"):
            src = ROOT / "samples/practice" / name
            shutil.copy(src, d)
            r = ch("raise", name, "--structure", "chhandas_anushtubh", "--sandhi", cwd=d)
            assert r.returncode == 0 and Path(d, name + ".chandah").exists() and Path(d, name + ".chandah.json").exists(), r.stdout + r.stderr
            r = ch("lower", name + ".chandah", cwd=d)
            lowered = Path(d) / (Path(name).stem + ".lowered" + Path(name).suffix)
            assert r.returncode == 0 and lowered.exists(), r.stdout + r.stderr
            assert core._tokens(lowered.read_text(encoding="utf-8")) == core._tokens(src.read_text(encoding="utf-8"))


def test_an_unreadable_character_is_refused_by_line():
    with tempfile.TemporaryDirectory() as d:
        Path(d, "bad.c").write_text("पूर्णाङ्क मुख्यम्(शून्य) {\n  प्रत्यागम 0 @ ;\n}\n", encoding="utf-8")
        r = ch("raise", "bad.c", cwd=d)
        assert r.returncode == 2 and "line 2" in r.stderr and "'@'" in r.stderr, r.stdout + r.stderr


def test_run_without_hindawi_says_so():
    env = {k: v for k, v in ENV.items() if k != "HINDAWI_HOME"}
    env["PATH"] = "/usr/bin:/bin"
    r = ch("run", "samples/practice/binary_search.c", env=env)
    assert r.returncode == 3 and "Hindawi is not here" in r.stderr, r.stdout + r.stderr


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


def test_the_manual_tables_are_read_from_the_code():
    from sutram_tool.mappings import TOKEN_WORDS
    manual = (ROOT / "docs" / "MANUAL.md").read_text(encoding="utf-8")
    missing = [t for t, w in TOKEN_WORDS.items() if f"| `{t.split('_')[0].replace('|', chr(92) + '|')}` | {w} |" not in manual]
    assert not missing, missing


def test_every_sample_built_and_run_by_hindawi_the_same():
    from chandah import core
    if core.hindawi_command() is None:
        raise Skip("Hindawi is not here")

    def one(f):
        src = f.read_text(encoding="utf-8")
        lowered, _ = core.check_paths(src)
        same, ra, rb = core.compile_compare(src, lowered, f.suffix)
        return f.name, same
    with cf.ThreadPoolExecutor(6) as ex:
        results = list(ex.map(one, SAMPLES))
    different = [n for n, same in results if not same]
    assert not different, different


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
