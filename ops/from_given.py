#!/usr/bin/env python3
"""from_given.py: make chandah's sutram_tool from the restore script exactly as given, changing only what is recorded:
the author's copyright lines at the head of every module, and the corrections in docs/CORRECTIONS.md (C1 and C2), and the completion
in ops/completion/ appended below each module it completes (docs/COMPLETION.md).
  from_given.py <restored tree> <chandah repository>
The restored tree is what `python3 given/restore_sutramv11.py <dir>` writes. A correction applies only to the exact text
it was written for; anything unexpected stops this before anything is written.
© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. MIT licence."""
import hashlib, sys
from pathlib import Path

HEADER = ("# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),\n"
          "# kept as given apart from these lines, the corrections in docs/CORRECTIONS.md and the completion below its marker.\n")

C1_OLD_PREPROC = '    ("PREPROC", r"\\#अन्तर्भाव"),\n'
C1_NEW_PREPROC = ('    ("COMMENT", r"/\\*.*?\\*/|//[^\\n]*"),  # C1: comments before operators, and line comments\n'
                  '    ("PREPROC", r"\\#अन्तर्भाव"),\n')
C1_OLD_COMMENT = '    ("COMMENT", r"/\\*.*?\\*/"),\n'

C2_ANCHOR = "def ensure_compiles("
C2_GIVEN_SHA256 = "1fbf1d6189c71940eda21953f3fe4f165668e734d97cb4d7ee90ce57a57c8ab6"
C2_NEW = '''def ensure_compiles(sanskrit_c_src: str):
    """Compile and run Sanskrit C through Hindawi, which lowers it through Romenagri to the host compiler.
    Returns (host_c, output): the program the compiler receives (`hin host sanskrit`) and what it prints
    (`hin run sanskrit`). Raises RuntimeError when Hindawi is not here, or the program does not build and run.
    C2: the given body replaced a fixed list of words and returned a binary-search result computed in Python,
    whatever the program; nothing here simulates a build."""
    import os, shutil, subprocess, sys, tempfile
    hin = shutil.which("hin")
    home = os.environ.get("HINDAWI_HOME", "")
    if hin:
        cmd = [hin]
    elif home and os.path.exists(os.path.join(home, "bin", "hin")):
        cmd = [sys.executable, os.path.join(home, "bin", "hin")]
    else:
        raise RuntimeError("Hindawi is not here: run the notebook's Installation cell, or set HINDAWI_HOME to a Hindawi tree")
    with tempfile.TemporaryDirectory() as d:
        path = os.path.join(d, "program.c")
        with open(path, "w", encoding="utf-8") as f:
            f.write(sanskrit_c_src)
        host = subprocess.run(cmd + ["host", "sanskrit", path], capture_output=True, text=True, timeout=300)
        run = subprocess.run(cmd + ["run", "sanskrit", path], stdin=subprocess.DEVNULL, capture_output=True, text=True, timeout=300)
    if host.returncode or run.returncode:
        raise RuntimeError("Hindawi could not build and run it:\\n" + (run.stderr or run.stdout or host.stderr).strip()[-2000:])
    return host.stdout, run.stdout
'''


def fail(msg):
    sys.exit(f"from_given: {msg}; nothing was written")


def main(src, dst):
    src, dst = Path(src), Path(dst)
    pkg = src / "sutram_tool"
    if not (pkg / "codec.py").exists():
        fail(f"no sutram_tool/ with codec.py under {src}")
    out = {p.name: p.read_text(encoding="utf-8") for p in sorted(pkg.glob("*.py"))}
    if len(out) != 16:
        fail(f"expected the 16 given modules, found {len(out)}")
    lx = out["lexer.py"]
    if lx.count(C1_OLD_PREPROC) != 1 or lx.count(C1_OLD_COMMENT) != 1:
        fail("lexer.py is not the given text C1 was written for")
    out["lexer.py"] = lx.replace(C1_OLD_COMMENT, "").replace(C1_OLD_PREPROC, C1_NEW_PREPROC)
    cd = out["codec.py"]
    i = cd.find(C2_ANCHOR)
    if i < 0 or hashlib.sha256(cd[i:].encode()).hexdigest() != C2_GIVEN_SHA256:
        fail("codec.py's ensure_compiles is not the given text C2 was written for")
    out["codec.py"] = cd[:i] + C2_NEW
    completion = Path(__file__).resolve().parent / "completion"
    for name in sorted(p.name for p in completion.glob("*.py")):
        if name not in out:
            fail(f"completion/{name} names no given module")
        out[name] = out[name].rstrip("\n") + "\n" + (completion / name).read_text(encoding="utf-8")
    target = dst / "sutram_tool"
    target.mkdir(parents=True, exist_ok=True)
    for name, text in out.items():
        (target / name).write_text(HEADER + text, encoding="utf-8")
    print(f"from_given: 16 modules, copyright applied, corrections C1 and C2 applied, completion appended, into {target}")


if __name__ == "__main__":
    if len(sys.argv) != 3:
        sys.exit(__doc__)
    main(sys.argv[1], sys.argv[2])
