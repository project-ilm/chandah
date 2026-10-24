# chandah manual

© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Hindawi™ is his trademark.

chandah raises a C or C++ program, in any language Hindawi supports, to chandah through the sutram layers, lowers it
back to compilable form, and builds and runs it with Hindawi, one program or a whole project. Its layers are sutram v11
(`given/restore_sutramv11.py`) with two corrections (`docs/CORRECTIONS.md`) and a completion that carries every token of
C and C++ in every language (`docs/COMPLETION.md`).

## How it sits on Hindawi

- The input is C or C++ as Hindawi writes it in a language: that language's keywords (its canonical bindings in
  `lang/hindawi/languages/<language>/c2h.uhin`) and its names, in its script. chandah keeps them exactly as written.
- chandah **raises** the program to chandah, words only, and **lowers** chandah back to the compilable program.
- Hindawi **builds and runs** it (`hin run <language> FILE`, `hindawi cc`, `hindawi build`); nothing in chandah
  imitates a build.

## The requirements, and how each is met

1. **Purpose.** A front end, the program to sutram and back; compiling stays Hindawi's (correction C2).
2. **Input.** C and C++, in every language Hindawi supports.
3. **Output.** Only words, spaces and newlines: every symbol is one short word (the tables below), every declaration
   is marked परिभाषित, a block opens with अणु and closes with पूर्ण, and the sutram comes back exactly on every path.
4. **Numerals.** Katapayadi syllables after अङ्क (`0` न, `1` क ... `9` झ, written in reverse, as tradition has it), or
   Devanagari digits; both come back. Digits written in a language's own script are kept as written, after स्वाङ्क.
5. **Structure.** None, samasa (each line, or the whole program) and chhandas (anushtubh, gayatri, trishtubh, jagati,
   syllables counted approximately), each with पङ्क्त्यन्त closing a line; a compound is formed only where it splits back.
6. **Sandhi.** Optional, after the structure, never before: visarga before s, ś and ṣ.
7. **Rule-based.** Every transformation is a table or a rule in the 16 files; array brackets, function parameters
   included, are words of their own (`[` सूच, `]` अवधि).
8. **Readable.** Short Sanskrit words, traditional where tradition has one (योग, ऊन, गुण, भाग, शेष, सम, यति, दण्ड).
9. **Modules.** The same 16 files; the completion is written below a marker at the end of the modules it completes.
10. **Acceptance test.** Passes, with `example_src.txt`.
11. **Compilation on every path.** Measured below.

## Install and use

```
pip install chandah-ilm
chandah raise prog.c --lang hindi                     # prog.c.chandah, and its metadata prog.c.chandah.json
chandah raise prog.c --structure chhandas_anushtubh --sandhi
chandah lower prog.c.chandah                          # prog.lowered.c, the compilable program
chandah run prog.c.chandah                            # lowered, then built and run by Hindawi; --input FILE gives it input
chandah check prog.c more.cpp --lang urdu             # all 26 paths there and back; Hindawi builds both, where it is here
chandah stages prog.c                                 # every layer of one program
chandah cc --lang sanskrit -O2 -o prog prog.c.chandah # like hindawicc: each .chandah lowered, then hindawi cc
chandah raise-tree project project.chandah            # every C and C++ file of a project to NAME.chandah
chandah build project.chandah --lang sanskrit -- -j8  # lowered, then hindawi build: the project's own make
chandah words                                         # the words, read from the tables
```

`--lang` is the program's language, sanskrit by default. A file raised with no structure needs nothing else to be
lowered; a file raised with samasa or chhandas needs the metadata written beside it. Exit codes: 0 done, 1 a check
failed, 2 the input could not be read or used, 3 Hindawi is needed and is not here.

## Measured

Every C and C++ sample in Hindawi 2026.10's galleries, in all eleven of their languages (dari, english, hindi, kannada,
pashto, punjabi, punjabi_shahmukhi, sanskrit, sindhi, telugu and urdu: 1,201 programs, byte-identical to the live
repository) and the notebook's two practice programs, through all 26 paths (two numeral modes; no structure, samasa by
line or whole, four chhandas; sandhi off and on): the sutram comes back exactly, no symbol is left in the chandah, every
token comes back, and every path lowers to the same program. Hindawi builds and runs the original and the lowered
program with the same exit and output. The acceptance test prints PASS, and the minimal example comes back.

## The words, read from the tables

Tokens (`TOKEN_WORDS`):

| token | word | |
|---|---|---|
| `=` | स्था | |
| `+=` | योगस्था | |
| `-=` | ऊनस्था | |
| `*=` | गुणस्था | |
| `/=` | भागस्था | |
| `%=` | शेषस्था | |
| `==` | सम | |
| `!=` | असम | |
| `<` | अल्प | |
| `>` | अधिक | |
| `<=` | अल्पसम | |
| `>=` | अधिकसम | |
| `+` | योग | |
| `-` | ऊन | |
| `*` | गुण | binary |
| `/` | भाग | |
| `%` | शेष | |
| `!` | न | |
| `&&` | च | |
| `\|\|` | वा | |
| `++` | वर्ध | |
| `--` | क्षय | |
| `&` | पता | unary |
| `*` | वस्तु | unary |
| `->` | द्वारा | |
| `.` | मध्ये | |
| `::` | क्षेत्र | |
| `{` | अणु | |
| `}` | पूर्ण | |
| `(` | समूह | |
| `)` | इति | |
| `[` | सूच | |
| `]` | अवधि | |
| `;` | दण्ड | |
| `,` | यति | |
| `:` | विसर्ग | |
| `?` | किम् | |
| `#` | पूर्व | |
| `##` | सन्धि | |
| `...` | आदि | |
| `~` | विलोम | |
| `^` | भेद | |
| `\|` | अथवा | |
| `&` | तथा | binary |
| `<<` | वाम | |
| `>>` | दक्ष | |
| `&=` | तथास्था | |
| `\|=` | अथवास्था | |
| `^=` | भेदस्था | |
| `<<=` | वामस्था | |
| `>>=` | दक्षस्था | |
| `.*` | मध्येवस्तु | |
| `->*` | द्वारावस्तु | |

Inside strings, characters and header names (`LITERAL_WORDS`); text in any script and Latin words stay as written, and
digits follow अङ्क:

| character | word |
|---|---|
| `space` | अन्तर |
| `.` | बिन्दु |
| `,` | यति |
| `:` | विसर्ग |
| `;` | दण्ड |
| `?` | किम् |
| `!` | विस्मय |
| `-` | ऊन |
| `+` | योग |
| `*` | गुण |
| `/` | भाग |
| `=` | स्था |
| `<` | अल्प |
| `>` | अधिक |
| `%` | शत |
| `&` | तथा |
| `\|` | अथवा |
| `^` | भेद |
| `~` | विलोम |
| `(` | समूह |
| `)` | इति |
| `[` | सूच |
| `]` | अवधि |
| `{` | अणु |
| `}` | पूर्ण |
| `#` | पूर्व |
| `"` | उद्धृत |
| `'` | लोप |
| `\\` | तिर्यक् |
| `_` | योजक |
| `$` | मुद्रा |
| `@` | विशेष |
| ``` | वक्र |
| `\t` | स्तम्भ |
| `\n` | नव |
| `%d` | पूर्णाङ्क |
| `%s` | पाठ |

Inside numbers (`NUMBER_CHAR_WORDS`):

| character | word |
|---|---|
| `.` | बिन्दु |
| `+` | योग |
| `-` | ऊन |
| `_` | योजक |
| `'` | लोप |

Markers:

| word | marks |
|---|---|
| परिभाषित | a declaration begins |
| अङ्क | a number follows |
| अङ्कादि | a number with a point, a base, an exponent or a suffix begins |
| अङ्कान्त | it ends |
| स्वाङ्क | digits in the language's own script follow, as written |
| वाक् | a string begins |
| वागन्त | it ends |
| अक्षर | a character begins |
| अक्षरान्त | it ends |
| उपसर्ग | L, u, U or u8 before a string or character |
| आवेशन | the include directive, अन्तर्भाव |
| मानकप्रवाह | <stdio.h> |
| शीर्ष | any other header name begins |
| शीर्षान्त | it ends |
| प्राचल | the ( of a function-like macro, written against its name |
| अनु | a backslash joining a line to the next |
| रिक्त | a line with no tokens |
| नाम | the next word is a name, though it reads like one of these words |
| यथा | inside a string: the next word is text, as it is |
| सङ्केत | inside a string: a character with no word of its own, by its number |
| पङ्क्त्यन्त | the end of a line, in samasa and chhandas |

## The 16 files

`ast_nodes.py`, `katapayadi.py`, `numerals.py`, `parser.py`, `sandhi_panini.py`, `chhandas.py`, `true_chhandas.py`,
`library_spine.py` and `__init__.py` are as given. `lexer.py` carries correction C1 and the completion's `lex_program`;
`codec.py` carries correction C2 and the completion's `encode` and `decode`; `mappings.py`, `forward.py`, `reverse.py`,
`sandhi_samasa.py` and `cli.py` carry the completion. v11's parse-tree path remains for the programs it covers.

## What chandah does not carry

Comments are dropped, with their lines kept so line numbers survive; the lowered program's layout is regenerated (one
space between tokens, four spaces a block). A character outside C, such as `@` outside a string, is refused with its
line.
