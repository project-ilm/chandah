# Corrections to sutram v11

© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI.

sutram v11 is kept as given (`given/restore_sutramv11.py`) apart from two lines of copyright at the head of every module,
the two corrections below, and the completion (docs/COMPLETION.md). `ops/from_given.py` applies each correction only to
the exact text it was written for, and the gate (V02) re-derives the package and compares it byte for byte.

## C1 · lexer.py: comments

**Given:** the comment pattern came after the operator pattern, so `/*` was read as two operators and any program with a
comment stopped the parser at the comment's first word. `//` comments were not recognised.
**Corrected:** comments are matched first, `/* ... */` and `// ...`, and skipped, as the given code intended.
**Evidence:** the notebook's binary search opens with a comment; with the given lexer it fails (`expected ( got binary`).

## C2 · codec.py: ensure_compiles

**Given:** `ensure_compiles` did not compile. It replaced a fixed list of words and seven fixed names, then returned
`5 -1` from a binary search written in Python, whatever program it was given ("gcc not available").
**Corrected:** it compiles and runs through Hindawi (`hin host sanskrit` and `hin run sanskrit`), returns
`(host_c, output)`, and raises `RuntimeError` when Hindawi is not here or the program does not build and run. Meta AI's
note of 23 October 2026 says the same: v11 does not compile; Hindawi does.

## Reported, not changed

- The HTML manual's word table does not describe the code (docs/MANUAL.md, the last sections).
- REGRESSION.md's "Remain" list (samasa typing, pratyahara compression, tinanta, anubandha) is the other AI's, kept as
  given in the restore script.
