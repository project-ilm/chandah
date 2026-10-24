# chandah manual: sutram v11, corrected and completed

© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Hindawi™ is his trademark.

sutram v11 was written by Meta AI under the direction of Abhishek Choudhary. What Meta AI gave is kept as given in
`given/`: the restore script, its HTML manual, its usage text, its note of 23 October 2026 and its requirements set. This
manual describes chandah as built: v11 with two corrections (`docs/CORRECTIONS.md`) and a completion that carries every
token of Sanskrit C and C++ (`docs/COMPLETION.md`).

## How it sits on Hindawi

- The input is Sanskrit C or C++ as Hindawi writes it: Hindawi's keywords (यदि, यावत्, प्रति, प्रत्यागम, पूर्णाङ्क ...),
  Devanagari names, and the rest of C. Hindawi's keywords are its canonical Sanskrit bindings
  (`lang/hindawi/languages/sanskrit/c2h.uhin`) and chandah keeps them exactly as written.
- chandah **raises** the program to chandah, words only, and **lowers** chandah back to compilable Sanskrit C.
- Hindawi **builds and runs** it, lowering through its script filter and Romenagri to the host compiler
  (`hin run sanskrit FILE`). Nothing in chandah imitates a build.

## Meta AI's requirements, and how each is met

1. **Purpose.** A front end, Sanskrit C to sutram and back. It does not compile; `ensure_compiles` hands the program to
   Hindawi (correction C2).
2. **Input.** Sanskrit C, and Sanskrit C++, as Hindawi writes it.
3. **Output.** Only words, spaces and newlines: every symbol is one word (the tables below), every declaration is marked
   परिभाषित, and the sutram comes back exactly (`dec_s == meta['base_sutram']`) on every path. v11's code opens a block
   with अणु and closes it with पूर्ण, though the requirement says the block ends with अणु; chandah keeps the code's words.
4. **Numerals.** Devanagari digits, or katapayadi syllables (`0` न, `1` क ... `9` झ, written in reverse, as tradition
   has it); both come back.
5. **Structure.** None, samasa (each line, or the whole program) and chhandas (anushtubh, gayatri, trishtubh, jagati,
   syllables counted approximately), each with पङ्क्त्यन्त closing a line. A compound is formed only where it splits back
   exactly, so samasa comes back whatever the program.
6. **Sandhi.** Optional, after the structure, never before: visarga before s, ś and ṣ, which comes back. `sandhi_panini.py`
   is kept as given beside it.
7. **Rule-based.** Every transformation is a table or a rule in the 16 files; array brackets, function parameters
   included, are words of their own (`[` सूचक, `]` सूचकान्त).
8. **Pandit-readable.** The words are Sanskrit: v11's, Hindawi's keywords, and traditional names for punctuation
   (अल्पविराम, उपविराम, विराम, प्रश्नचिह्न).
9. **Modules.** The same 16 files; the completion is written below a marker at the end of the modules it completes.
10. **Acceptance test.** Passes, with `example_src.txt` (the notebook's binary search).
11. **Compilation on every path.** Measured below.

## Install and use

```
pip install chandah-ilm
chandah raise prog.c                       # prog.c.chandah, and its metadata prog.c.chandah.json
chandah raise prog.c --structure chhandas_anushtubh --sandhi --numerals katapayadi
chandah lower prog.c.chandah               # prog.lowered.c: compilable Sanskrit C
chandah run prog.c.chandah                 # lowered, then built and run by Hindawi; --input FILE gives it input
chandah check prog.c more.cpp ...          # all 26 paths there and back; Hindawi builds both, where it is here
chandah stages prog.c                      # every layer of one program
chandah words                              # the words, read from the tables
```

Exit codes: 0 done, 1 a check failed, 2 the input could not be read or used, 3 Hindawi is needed and is not here. In
Python: `from sutram_tool import codec`; `enc, meta = codec.encode(src, numeral_mode, structure, apply_sandhi)`;
`program, base = codec.decode(enc, meta)`.

## Measured

Every Sanskrit C and C++ sample of Hindawi 2026.10 (`samples/`: the gallery's 114, the same in the live repository, and
the notebook's two), 116 programs, through all 26 paths (two numeral modes; no structure, samasa by line or whole, four
chhandas; sandhi off and on): the sutram comes back exactly, no symbol is left in the chandah, every token comes back, and
every path lowers to the same program. Hindawi builds and runs every original and its lowered program with the same exit
and the same output. Meta AI's acceptance test prints PASS, and its minimal example comes back.

## The words, read from the tables

Tokens (`TOKEN_WORDS`; v11's words where v11 had them, `->` given its own because v11 shared मध्ये with `.`):

| token | word | |
|---|---|---|
| `=` | स्थापय | |
| `+=` | योजयस्थापय | |
| `-=` | वियोजयस्थापय | |
| `*=` | गुणयस्थापय | |
| `/=` | विभजस्थापय | |
| `%=` | शेषस्थापय | |
| `==` | समम् | |
| `!=` | नसमम् | |
| `<` | अल्पतरम् | |
| `>` | अधिकतरम् | |
| `<=` | अल्पतरंवासमम् | |
| `>=` | अधिकतरंवासमम् | |
| `+` | योजय | |
| `-` | वियोजय | |
| `*` | गुणय | binary |
| `/` | विभज | |
| `%` | शेषम् | |
| `!` | न | |
| `&&` | च | |
| `\|\|` | वा | |
| `++` | वर्धय | |
| `--` | क्षपय | |
| `&` | पता | unary |
| `*` | अन्तर्वस्तु | unary |
| `->` | निर्देशमध्ये | |
| `.` | मध्ये | |
| `::` | क्षेत्र | |
| `{` | अणु | |
| `}` | पूर्ण | |
| `(` | समूहारम्भ | |
| `)` | समूहान्त | |
| `[` | सूचक | |
| `]` | सूचकान्त | |
| `;` | विराम | |
| `,` | अल्पविराम | |
| `:` | उपविराम | |
| `?` | प्रश्नचिह्न | |
| `#` | पूर्वनिर्देश | |
| `...` | इत्यादि | |
| `~` | पूरक | |
| `^` | अनन्यवा | |
| `\|` | अंशवा | |
| `&` | अंशच | binary |
| `<<` | वामसर्पय | |
| `>>` | दक्षिणसर्पय | |
| `&=` | अंशचस्थापय | |
| `\|=` | अंशवास्थापय | |
| `^=` | अनन्यवास्थापय | |
| `<<=` | वामसर्पयस्थापय | |
| `>>=` | दक्षिणसर्पयस्थापय | |
| `.*` | मध्येअन्तर्वस्तु | |
| `->*` | निर्देशमध्येअन्तर्वस्तु | |

Inside strings, characters and header names (`LITERAL_WORDS`); Devanagari text and Latin words stay as written, and digits
follow संख्याङ्क:

| character | word |
|---|---|
| `space` | अवकाश |
| `.` | बिन्दु |
| `,` | अल्पविराम |
| `:` | उपविराम |
| `;` | विराम |
| `?` | प्रश्नचिह्न |
| `!` | विस्मयचिह्न |
| `-` | वियोजय |
| `+` | योजय |
| `*` | गुणय |
| `/` | विभज |
| `=` | स्थापय |
| `<` | अल्पतरम् |
| `>` | अधिकतरम् |
| `%` | प्रतिशत |
| `&` | अंशच |
| `\|` | अंशवा |
| `^` | अनन्यवा |
| `~` | पूरक |
| `(` | समूहारम्भ |
| `)` | समूहान्त |
| `[` | सूचक |
| `]` | सूचकान्त |
| `{` | अणु |
| `}` | पूर्ण |
| `#` | पूर्वनिर्देश |
| `"` | उद्धरणचिह्न |
| `'` | एकोद्धरणचिह्न |
| `\\` | पलायनचिह्न |
| `_` | योजक |
| `$` | मुद्राचिह्न |
| `@` | विशेषचिह्न |
| ``` | प्रत्युद्धरणचिह्न |
| `\t` | स्तम्भान्तर |
| `\n` | नूतनपङ्क्ति |
| `%d` | प्रारूपपूर्णाङ्क |
| `%s` | प्रारूपपाठ |

Inside numbers (`NUMBER_CHAR_WORDS`):

| character | word |
|---|---|
| `.` | दशमलव |
| `+` | योजय |
| `-` | वियोजय |
| `_` | योजक |
| `'` | एकोद्धरणचिह्न |

Markers:

| word | marks |
|---|---|
| परिभाषित | a declaration begins (v11's) |
| संख्याङ्क | a number follows (v11's) |
| संख्यारूप | a number with a point, a base, an exponent or a suffix begins |
| संख्यारूपान्त | it ends |
| देवाङ्क | Devanagari digits written as such in the source follow |
| उद्धरणारम्भ | a string begins (v11's) |
| उद्धरणान्त | it ends (v11's) |
| वर्णारम्भ | a character begins |
| वर्णान्त | it ends |
| उद्धरणोपसर्ग | L, u, U or u8 before a string or character |
| आवेशन | the include directive, अन्तर्भाव (v11's) |
| मानकप्रवाह | <stdio.h> (v11's) |
| शीर्षकारम्भ | any other header name begins |
| शीर्षकान्त | it ends |
| प्राचलारम्भ | the ( of a function-like macro, written against its name |
| पङ्क्तिसन्धि | a backslash joining a line to the next |
| रिक्तपङ्क्ति | a line with no tokens, so line numbers survive |
| नाम | the next word is a name, though it reads like one of these words |
| शब्दशः | inside a string: the next word is text, though it reads like one of these words |
| वर्णसङ्केत | inside a string: a character with no word of its own, by its number |
| पङ्क्त्यन्त | the end of a line, in samasa and chhandas (v11's) |

## The 16 files

`ast_nodes.py`, `katapayadi.py`, `numerals.py`, `parser.py`, `sandhi_panini.py`, `chhandas.py`, `true_chhandas.py`,
`library_spine.py` and `__init__.py` are as given. `lexer.py` carries correction C1 and the completion's `lex_program`;
`codec.py` carries correction C2 and the completion's `encode` and `decode`; `mappings.py`, `forward.py`, `reverse.py`,
`sandhi_samasa.py` and `cli.py` carry the completion. v11's parse-tree path (`parse_source`, `program_to_sutram`,
`parse_sutram`) remains as given for the programs it covers.

## Corrections to the given usage text

- **Setup:** `sys.path.insert(0, '/path/to/restored')` is not needed once chandah-ilm is installed.
- **lexer.py:** it reads Sanskrit C as Hindawi writes it, not "C-like source"; comments no longer stop it (C1).
- **reverse.py:** `parse_sutram` returns the Sanskrit C text, not `(preprocs, funcs)`.
- **codec.py:** `structure` is also `chhandas_gayatri`, `chhandas_trishtubh` or `chhandas_jagati`; `decode` returns
  Sanskrit C and the base sutram; `ensure_compiles` compiles through Hindawi and returns `(host_c, output)` (C2).
- **cli.py:** `sutram_to_c` returns Sanskrit C.
- **true_chhandas.py:** `parse_true_chhandas` gives the sutram back; `strip_true_fillers` alone does not.
- **library_spine.py:** `list_core()` holds 30 verbs, not the 32 REGRESSION.md and the HTML manual state.
- **`__init__.py`** was given as "init.py".

## Where the HTML manual differs from the code

10 of its 22 rows differ from the code. Its word for `return`, प्रत्यर्पय, is not Hindawi's either.

| token | the HTML manual | the code | |
|---|---|---|---|
| `=` | स्थापय | स्थापय | agrees |
| `+` | योजय | योजय | agrees |
| `−` | वियोजय | वियोजय | agrees |
| `*` | गुणय | गुणय | agrees |
| `/` | विभज | विभज | agrees |
| `%` | शेषय | शेषम् | differs |
| `==` | समम् | समम् | agrees |
| `!=` | असमम् | नसमम् | differs |
| `<` | न्यूनम् | अल्पतरम् | differs |
| `>` | अधिकम् | अधिकतरम् | differs |
| `<=` | अनधिकम् | अल्पतरंवासमम् | differs |
| `>=` | अन्यूनम् | अधिकतरंवासमम् | differs |
| `int` | पूर्णाङ्क | पूर्णाङ्क (keyword, as written) | agrees |
| `return` | प्रत्यर्पय | प्रत्यागम (keyword, as written) | differs |
| `if` | यदि | यदि (keyword, as written) | agrees |
| `else` | अन्यथा | अन्यथा (keyword, as written) | agrees |
| `while` | यावत् | यावत् (keyword, as written) | agrees |
| `break` | विरम | भङ्ग (keyword, as written) | differs |
| `;` | विराम | विराम | agrees |
| `,` | अल्पविराम | अल्पविराम | agrees |
| `{` | प्रारम्भ | अणु | differs |
| `}` | अवसान | पूर्ण | differs |

## What chandah does not carry

Comments are dropped, with their lines kept so line numbers survive; the lowered program's layout is regenerated (one
space between tokens, four spaces a block). A character outside C, such as `@` outside a string, is refused with its
line. A name already containing योजक comes back by an avagraha the completion adds.
