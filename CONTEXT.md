# CONTEXT: chandah

© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI.

## What it answers

The author's instructions of 23 and 24 October 2026. sutram v11, his interim implementation of the sutram layer over the
Sanskrit layer of Hindawi 2026.10, is seeded separately in project-ilm as chandah, with his copyright and the estate's
contracts and context. It is completed so that every sample raises to chandah, lowers to compilable form and builds, on
every path, in every language Hindawi supports, with short words (च and न as they were); the notebook has one IDE; the
command line is fit for release, with build options like hindawicc that build straight from chandah; and each version is
seeded, minted and released on PyPI. The copyright, the intention and the algorithm are his. Retrieve, do not
reconstruct.

## Where it sits

Hindawi (hindawiai/hindawi2026.10) is the canon (master contract C47): its keywords, its lowering through the script
filter and Romenagri, its compilers and its project builder. chandah works on the program's text and hands building to
Hindawi (`hin run`, `hindawi cc`, `hindawi build`).

## Work retrieved before building

- sutram v11, kept byte for byte as `given/restore_sutramv11.py` (sha256
  9a3eaadaeeb88d1105e20d7dd8e599c723f6577ba243f8fd5a6733b046950692), cleaned of invisible characters before it was read.
- The notebook: hindawiai/hindawi2026.10@b53530f `notebooks/practice/hindawi_sanskrit.ipynb` (`given/`), and its IDE,
  `lang/hindawi/tools/nb_ide.py`, whose helpers the one IDE uses.
- The samples: every C and C++ program of that commit's galleries, eleven languages, byte-identical to the live repository.
- Every language's declaration and control keywords, read from Hindawi's tables (`chandah/languages.json`, 75 languages).
- Hindawi's drivers: `hindawi cc` (hindawicc) and `hindawi build` (build_project.py), which chandah's build options wrap.
- project-ilm/chandah as it stands: the first version minted on 23 October 2026 (10.5281/zenodo.23589959), and his own
  commit of 24 October.

## Choices made in this build, flagged for the author

- The words: the chosen words shortened (स्था, योग, ऊन, गुण, भाग, सम, अल्प, अधिक ...), च, न and वा as they were, and short
  words for the rest; all listed in docs/MANUAL.md and data in `mappings.py`.
- The chandah words stay in Devanagari for every language; keywords and names stay in the language's own script.
- Comments are not carried (their lines are); the lowered program's layout is regenerated.
- The PyPI name chandah-ilm; the licence MIT; the version 2026.10.1.

## Evidence states

- 1,201 gallery programs in eleven languages and the two practice programs through all 26 paths and back: verified here.
- Hindawi builds and runs originals and lowered programs with the same output: verified here for every sample of
  Sanskrit and Urdu, and for the languages listed in docs/MANUAL.md.
- The one IDE: driven here outside Colab; in Colab once chandah-ilm 2026.10.1 is on PyPI (the install cell falls back to
  the repository until then).

## Open

1. Rendering chandah's words in each language's own script, for the scripts where that comes back exactly.
2. The Paninian sandhi of `sandhi_panini.py` in the codec's path, beside the visarga sandhi.
