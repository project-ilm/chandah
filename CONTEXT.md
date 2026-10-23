# CONTEXT: chandah

© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI.

## What it answers

The author's instruction of 23 October 2026: the sutram v11 implementation is an interim implementation of the sutram
layer that can be applied on top of the Sanskrit layer of Hindawi 2026.10. It is to be seeded separately in project-ilm as
chandah, with his copyright and the estate's contracts and context; it was created by Meta AI under his direction. The
existing Sanskrit notebook of ilm_sa is to be adapted so that users can take any Sanskrit C or Sanskrit C++ file to chandah,
through all its stages and layers, revert it and compile it; the notebook is to be derived from the ilm_sa one, with the
chandah tools placed cleanly in the IDE and in the later explanation sections. The other AI's manual and tool description
do not understand how Hindawi works and are to be given basic corrections. It is to be seeded and minted per the estate's
SOP and released on PyPI. Retrieve, do not reconstruct.

## Where it sits

Hindawi (hindawiai/hindawi2026.10) is the canon (master contract C47): its Sanskrit keywords, its lowering through the
script filter and Romenagri, its compilers. chandah works on the Sanskrit C text, above the Sanskrit layer, and leaves
building and running to Hindawi. Its notebook is Hindawi's Sanskrit notebook with chandah added.

## Work retrieved before building

- The given restore script, kept byte for byte as `given/restore_sutramv11.py` (sha256
  9a3eaadaeeb88d1105e20d7dd8e599c723f6577ba243f8fd5a6733b046950692, 97,434 bytes), received 23 October 2026 and cleaned of
  invisible characters before it was read: none were found. It restores the 16 modules of sutram_tool and REGRESSION.md.
- The given HTML manual, `given/sutram-manual-v11.html` (sha256
  c9dedc21eccbe062069c0956513c5167ea6456e8ec82bb8c13746145babc0033, 190,375 bytes), also clean. It carries the manual
  only; the code is not in it.
- The given usage text, as he pasted it, `given/usage-v11.md`.
- The notebook: the ilm_sa page (project-ilm/ilm_sa@f5a4cff) opens hindawiai/hindawi2026.10@b53530f
  `notebooks/practice/hindawi_sanskrit.ipynb`, kept as `given/hindawi_sanskrit.ipynb`.
- Hindawi's canonical Sanskrit bindings (`lang/hindawi/languages/sanskrit/c2h.uhin`): while यावत्, if यदि, else अन्यथा,
  return प्रत्यागम, int पूर्णाङ्क, void शून्य, #include #अन्तर्भाव; the given code's keywords, types and preprocessor word
  are exactly these. Hindawi's `hin` builds and runs (`hin run sanskrit FILE`) and shows the host program
  (`hin host sanskrit FILE`).
- zistgah/governance@773a1df: the master contract, C1 to C48.
- The seeders of hmnsq/paras and hmnsq/satsneha, whose shape `seed_chandah.sh` keeps.

## Choices made in this build, flagged for the author

- Two corrections in the code, recorded in docs/CORRECTIONS.md: C1 (comments in the lexer) and C2 (ensure_compiles
  compiles through Hindawi instead of simulating). Everything else in the code is as given, with his copyright added.
- The PyPI name is chandah-ilm, beside burp-ilm and paras-ilm; it installs the `chandah` command and two packages,
  `chandah` (this repository's) and `sutram_tool` (the given code, under its own name so the given usage still works).
- The version is 2026.10.0. The licence is MIT, as for paras, BURP and satsneha. No new trademark is claimed.
- chandah shows numerals as katapayadi from its second layer on, the mode that comes back in every structure.

## Evidence states

- The notebook's binary search through every layer and back: verified here, 13 of 13 combinations with katapayadi
  numerals, 5 of 13 with Devanagari numerals.
- Built and run by Hindawi, original and reverted (chhandas anushtubh, katapayadi, sandhi): verified here, both `5 -1`.
- Coverage: one of the 114 programs in Hindawi's Sanskrit GATE gallery; the notebook's C++ program is refused.
- The notebook: derived and checked (V03); its cells run in Colab only once chandah-ilm is on PyPI.

## Open

1. Widening the parser to the whole of Hindawi's Sanskrit C (for, break, continue, char and the other types, declarations
   outside functions, other headers), then Sanskrit C++.
2. Devanagari numerals with samasa and sandhi.
3. REGRESSION.md's "Remain" list, as the other AI gave it.
