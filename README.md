# chandah: Sanskrit C through the sutram layers to chandas, and back

**chandah** takes a Sanskrit C program, as Hindawi writes it, through the sutram layers (words for every operator,
katapayadi numerals, samasa, Paninian sandhi, and chhandas in anushtubh, gayatri, trishtubh or jagati), checks that every
layer comes back exactly, reverts it, and lets Hindawi build and run the original and the reverted program so the outputs
can be compared. The layers are sutram v11, written by Meta AI under the direction of Abhishek Choudhary, with the basic
corrections in [docs/CORRECTIONS.md](docs/CORRECTIONS.md).

```
pip install chandah-ilm
chandah stages program.c       # every layer, each checked on the way back
chandah revert program.c       # to chandah and back, then built and run by Hindawi, original and reverted compared
```

Open it in a notebook: [the chandah notebook](https://colab.research.google.com/github/project-ilm/chandah/blob/main/notebooks/chandah_sanskrit.ipynb),
which is Hindawi 2026.10's Sanskrit notebook with chandah added beside the IDE, in the C and C++ practice sections, and in
its own explanation. The manual, corrected: [docs/MANUAL.md](docs/MANUAL.md).

## What it covers, as measured

The notebook's binary search comes back exactly through every layer with katapayadi numerals (13 of 13 combinations), and
Hindawi builds and runs the original and the reverted program with the same output. v11's parser covers a small part of
Sanskrit C (docs/MANUAL.md, Coverage): one program of the 114 in Hindawi's Sanskrit GATE gallery, and no C++. A program
outside it is refused by name, never half-converted.

## Where it sits

Hindawi (hindawiai/hindawi2026.10) is the canon: its keywords, its lowering through Romenagri, its compilers. chandah works
on the Sanskrit C text and leaves building and running to Hindawi. The repository follows the estate's master contract
(zistgah/governance); see CONTRACT.md, CONTEXT.md and AGENTS.md.

© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. MIT licence (LICENSE). Hindawi™ is his trademark.
