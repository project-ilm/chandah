# CONTEXT: chandah

© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI.

## What it answers

The author's instructions of 23 October 2026. First: sutram v11 is an interim implementation of the sutram layer to be
applied on top of the Sanskrit layer of Hindawi 2026.10; seed it separately in project-ilm as chandah, with his copyright
and the estate's contracts and context (Meta AI made it under his direction); adapt the Sanskrit notebook of ilm_sa so that
any Sanskrit C or Sanskrit C++ file can be taken to chandah through all its stages and layers, reverted and compiled; give
the other AI's manual and tool description basic corrections; seed and mint per the SOP and release on PyPI; retrieve,
do not reconstruct. Then: complete it; one IDE in the notebook; include all the samples; allow raising to chandah and
lowering to compilable form; ensure it compiles; meet Meta AI's requirements set; make the command line good for release.

## Where it sits

Hindawi (hindawiai/hindawi2026.10) is the canon (master contract C47): its Sanskrit keywords, its lowering through the
script filter and Romenagri, its compilers. chandah works on the Sanskrit C text, above the Sanskrit layer, and leaves
building and running to Hindawi.

## Work retrieved before building

- The given restore script, kept byte for byte as `given/restore_sutramv11.py` (sha256
  9a3eaadaeeb88d1105e20d7dd8e599c723f6577ba243f8fd5a6733b046950692, 97,434 bytes), cleaned of invisible characters before
  it was read: none were found. It restores the 16 modules of sutram_tool and REGRESSION.md.
- The given HTML manual (`given/sutram-manual-v11.html`, sha256 c9dedc21eccbe062069c0956513c5167ea6456e8ec82bb8c13746145babc0033),
  the usage text (`given/usage-v11.md`), Meta AI's note (`given/meta-ai-note-2026-10-23.md`) and its requirements set
  (`given/requirements-v11.md`), each as relayed and clean.
- The notebook: the ilm_sa page (project-ilm/ilm_sa@f5a4cff) opens hindawiai/hindawi2026.10@b53530f
  `notebooks/practice/hindawi_sanskrit.ipynb` (`given/hindawi_sanskrit.ipynb`); its IDE is `lang/hindawi/tools/nb_ide.py`
  at the same commit, whose helpers the one IDE uses.
- The samples: every Sanskrit C and C++ program in that commit's `docs/hindawi/samples/sanskrit` (114, byte-identical to
  the copy tested) and the notebook's two practice programs, in `samples/`.
- Hindawi's canonical Sanskrit keywords (`c2h.uhin`, `cpp2h.uhin`): the declaration keywords and v11's keywords, types and
  include word are exactly these.
- zistgah/governance@773a1df: the master contract, C1 to C48. The seeders of hmnsq/paras and hmnsq/satsneha, whose shape
  `seed_chandah.sh` keeps.

## Choices made in this build, flagged for the author

- The completion adds words: for the tokens v11 did not name (`]` सूचकान्त, `;` विराम and `,` अल्पविराम from v11's own
  HTML manual, `:` उपविराम, `?` प्रश्नचिह्न, and the rest), for characters inside strings, and its markers. All are listed
  in docs/MANUAL.md and are data in `mappings.py`.
- `->` gets निर्देशमध्ये, because v11 gave it the same word as `.` and a word must name one token.
- Blocks open with अणु and close with पूर्ण, as v11's code has it; the requirements set says the block ends with अणु.
- Comments are not carried (their lines are); the lowered program's layout is regenerated.
- The notebook's IDE cell is the one IDE (Hindawi's, every action kept, chandah's row added); every other given cell is
  unchanged. The PyPI name is chandah-ilm; the licence MIT; the version 2026.10.0; no new trademark is claimed.

## Evidence states

- 116 samples through all 26 paths and back, no symbol left, every token back, one lowered program per sample: verified here.
- Hindawi builds and runs every original and lowered sample with the same output: verified here (Hindawi 2026.10 tables).
- Meta AI's acceptance test and minimal example: verified here.
- The one IDE: driven here outside Colab (load, build, raise, lower, build, check); in Colab once chandah-ilm is on PyPI.

## Open

1. The words the completion adds, for the author (and a pandit) to confirm.
2. The Paninian sandhi of `sandhi_panini.py` in the codec's path, beside v11's visarga sandhi.
3. REGRESSION.md's "Remain" list, as the other AI gave it.
