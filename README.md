# chandah: C to chandah and back, in every language Hindawi supports

**chandah** raises a C or C++ program, as Hindawi writes it in any of its languages, to chandah through the sutram layers
(one short word for every symbol, katapayadi numerals, samasa, sandhi, and chhandas in anushtubh, gayatri, trishtubh or
jagati), lowers it back to compilable form, and lets Hindawi build and run it, one program or a whole project.

```
pip install chandah-ilm
chandah raise prog.c --lang sanskrit --structure chhandas_anushtubh --sandhi   # prog.c.chandah and its metadata
chandah lower prog.c.chandah                                                    # prog.lowered.c
chandah run prog.c.chandah                                                      # built and run by Hindawi
chandah check prog.c                                                            # all 26 paths there and back, and the build
chandah cc --lang sanskrit -o prog prog.c.chandah                               # like hindawicc, from chandah
chandah build project.chandah --lang sanskrit -- -j8                            # a whole project, its own make
```

Open it in a notebook: [the chandah notebook](https://colab.research.google.com/github/project-ilm/chandah/blob/main/notebooks/chandah_sanskrit.ipynb),
Hindawi 2026.10's Sanskrit notebook with one IDE: Hindawi's own, with Raise to chandah, Lower to compilable form and Check
every path beneath its editor, for whichever language is chosen. The manual: [docs/MANUAL.md](docs/MANUAL.md).

## What it carries, as measured

Every C and C++ sample of Hindawi 2026.10's galleries, in all eleven of their languages (1,201 programs, in `samples/`),
and the notebook's two, through all 26 paths: each comes back exactly, with no symbol left in the chandah, and Hindawi
builds and runs the original and the lowered program with the same output.

## Where it sits

Hindawi (hindawiai/hindawi2026.10) is the canon: its keywords, its lowering through Romenagri, its compilers. chandah works
on the program's text and leaves building and running to Hindawi. The repository follows the estate's master contract
(zistgah/governance); see CONTRACT.md, CONTEXT.md and AGENTS.md.

© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. MIT licence (LICENSE). Hindawi™ is his trademark.
