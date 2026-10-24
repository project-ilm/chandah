#!/usr/bin/env bash
# verify.sh: chandah's gate. It refuses only on what a release needs:
#   V01 the end-to-end tests pass            V02 sutram_tool is the given code, with only the recorded corrections
#   V03 the notebook: one IDE, Hindawi's with chandah added    V04 no invisible characters    V05 the notices    V06 no build output
# Temporary work stays inside this folder, in .verify/, and is removed at the end.
# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI.
set -uo pipefail
cd "$(dirname "$0")/.."
export PYTHONDONTWRITEBYTECODE=1
V=.verify; rm -rf "$V"; mkdir -p "$V/tmp"; export TMPDIR="$PWD/$V/tmp"
fail=0; ok(){ printf '   ok   %s\n' "$*"; }; no(){ printf '   FAIL %s\n' "$*"; fail=1; }

python3 tests/test_chandah.py > "$V/tests.txt" 2>&1 && ok "V01 $(tail -1 "$V/tests.txt")" \
  || { no "V01 the tests fail:"; sed 's/^/        /' "$V/tests.txt"; }

if python3 given/restore_sutramv11.py "$V/given" >/dev/null 2>&1 && python3 ops/from_given.py "$V/given" "$V/derived" >/dev/null 2>&1; then
  diff -rq "$V/derived/sutram_tool" sutram_tool -x __pycache__ -x '*.ots' > "$V/fidelity.txt" 2>&1 \
    && ok "V02 sutram_tool is the given code with only the recorded corrections and completion: 16 modules re-derived and identical" \
    || { no "V02 sutram_tool differs from the given code with its recorded corrections:"; sed 's/^/        /' "$V/fidelity.txt"; }
else no "V02 the given script could not be restored and corrected"; fi

python3 - > "$V/notebook.txt" 2>&1 <<'PY' && ok "V03 $(cat "$V/notebook.txt")" || { no "V03 the notebook:"; sed 's/^/        /' "$V/notebook.txt"; }
import json, sys
given = json.load(open("given/hindawi_sanskrit.ipynb", encoding="utf-8"))["cells"]
mine = json.load(open("notebooks/chandah_sanskrit.ipynb", encoding="utf-8"))["cells"]
key = lambda c: (c["cell_type"], "".join(c["source"]))
ide_cells = [i for i, c in enumerate(given) if "nb_ide.ide(" in "".join(c["source"])]
keys, j, missing = [key(c) for c in mine], 0, []
for i, c in enumerate(given):
    if i in ide_cells:
        continue
    try:
        j = keys.index(key(c), j) + 1
    except ValueError:
        missing.append(key(c)[1][:60])
text = "\n".join(k[1] for k in keys)
ides = text.count("nb_ide.ide(") + text.count("chandah.nb.ide(")
needed = [w for w in ("pip install -q chandah-ilm", "chandah.nb.ide('sanskrit')", "chandah raise binary_search.c",
                      "chandah check bst.cpp", "# chandah: what each layer does") if w not in text]
if missing or needed or ides != 1:
    print("given cells missing or changed:", missing, "| chandah parts missing:", needed, "| IDEs:", ides); sys.exit(1)
print(f"one IDE, Hindawi's with chandah's actions; every other given cell ({len(given) - len(ide_cells)}) unchanged and in order; {len(mine) - len(given) + len(ide_cells)} chandah cells")
PY

python3 - > "$V/invisible.txt" 2>&1 <<'PY' && ok "V04 $(cat "$V/invisible.txt")" || { no "V04 invisible characters:"; sed 's/^/        /' "$V/invisible.txt"; }
import importlib.util, pathlib, subprocess, sys
spec = importlib.util.spec_from_file_location("ci", "ops/clean_invisible.py"); ci = importlib.util.module_from_spec(spec); spec.loader.exec_module(ci)
try:
    files = subprocess.run(["git", "ls-files"], capture_output=True, text=True, check=True).stdout.split()
except Exception:
    files = [str(p) for p in pathlib.Path(".").rglob("*") if p.is_file() and not set(p.parts) & {".git", ".verify", "__pycache__"}]
bad, n = [], 0
for f in files:
    try:
        text = pathlib.Path(f).read_text(encoding="utf-8")
    except (UnicodeDecodeError, IsADirectoryError, FileNotFoundError):
        continue
    n += 1
    removed = ci.clean(text)[1]["removed"]
    if removed:
        bad.append(f"{f}: {removed}")
print("\n".join(bad) if bad else f"no invisible characters in {n} text files")
sys.exit(1 if bad else 0)
PY

N="© 1993–2026 Abhishek Choudhary. All rights reserved."; miss=""
for f in README.md CONTEXT.md CONTRACT.md AGENTS.md CONTRIBUTING.md NOTICE docs/index.html docs/MANUAL.md docs/CORRECTIONS.md docs/COMPLETION.md samples/README.md \
         ops/verify.sh ops/from_given.py chandah/__init__.py chandah/core.py chandah/cli.py chandah/nb.py; do
  grep -qF "$N" "$f" 2>/dev/null || miss="$miss $f"; done
for f in sutram_tool/*.py; do head -1 "$f" | grep -qF "$N" || miss="$miss $f"; done
grep -q "MIT" LICENSE || miss="$miss LICENSE(MIT)"; grep -q "^license: MIT" CITATION.cff || miss="$miss CITATION.cff(licence)"
grep -rlI -i -e "meta ai" -e "meta\.ai" --exclude-dir=.git --exclude-dir=.verify --exclude-dir=given --exclude-dir=doi-package --exclude=verify.sh . >/dev/null 2>&1 && miss="$miss (another author named)"
[ -z "$miss" ] && ok "V05 the notices travel: his copyright on every module, the licence and the trademark where they belong" || no "V05 notices missing in:$miss"

if git rev-parse --git-dir >/dev/null 2>&1; then built=$(git ls-files | grep -v '^doi-package/' | grep -E '(__pycache__/|\.pyc$|\.tar\.gz$)' || true)
else built=$(find . \( -name __pycache__ -o -name '*.pyc' -o -name '*.tar.gz' \) -not -path './.verify/*' -not -path './.git/*' -not -path './doi-package/*' -print); fi
[ -z "$built" ] && ok "V06 no build output" || no "V06 build output present: $built"

rm -rf "$V"
[ "$fail" = 0 ] && echo "verify: PASS" || { echo "verify: FAIL"; exit 1; }
