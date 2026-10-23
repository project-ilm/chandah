# chandah manual: sutram v11, corrected

© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Hindawi™ is his trademark.

sutram v11 was written by Meta AI under the direction of Abhishek Choudhary. This manual is the usage text Meta AI gave
(kept as given in `given/usage-v11.md`) with basic corrections, each marked **Correction** and each checked by running the
code. The HTML manual it also gave is kept as given in `given/sutram-manual-v11.html`; where it does not describe the code,
the code is described here and the differences are listed at the end. The two corrections made to the code itself are in
`docs/CORRECTIONS.md`.

## How it sits on Hindawi

- **The input is Sanskrit C as Hindawi writes it**, not a C-like language of its own: Hindawi's keywords (यदि, यावत्,
  अन्यथा, प्रत्यागम, पूर्णाङ्क, शून्य, `#अन्तर्भाव`), Devanagari names, and the rest of C. Those keywords are Hindawi's
  canonical Sanskrit bindings (`lang/hindawi/languages/sanskrit/c2h.uhin` in hindawiai/hindawi2026.10), and v11 keeps them
  exactly as written.
- **Hindawi builds and runs the program.** It lowers Sanskrit C through its script filter and Romenagri to the host
  compiler (`hin run sanskrit FILE`); nothing in chandah replaces or imitates that.
- **chandah works on the text**: the sutram layers turn the program into words, numerals, compounds, sandhi and metre,
  and back. A program that comes back is built and run again by Hindawi, so the two outputs can be compared.

## Install and use

```
pip install chandah-ilm            # in the notebook, its chandah cell does this
chandah stages program.c           # every layer, each checked on the way back
chandah revert program.c           # to chandah and back; Hindawi builds and runs both, and the outputs are compared
chandah encode program.c -o program.chandah   # with --numerals, --structure, --no-sandhi
chandah decode program.chandah --meta program.chandah.meta.json -o back.c
chandah words                      # the words v11 uses, read from its own tables
```

In Python, `from sutram_tool import codec` works once the package is installed. **Correction:** the given setup line
`sys.path.insert(0, '/path/to/restored')` is not needed.

## The 16 files

1. **lexer.py.** `toks = lex(src)` returns a list of `(kind, text)` pairs. **Correction:** it tokenises Sanskrit C as
   Hindawi writes it (Devanagari and Latin names, ASCII and Devanagari digits, strings, operators, `#अन्तर्भाव`), not
   "C-like source". **Correction C1:** the given lexer matched `/*` as two operators, so any program with a comment
   failed; comments are now skipped, `//` comments too.
2. **parser.py.** `preprocs, funcs = parse_source(src)`. **Correction:** what it covers is listed below under Coverage;
   anything else stops it, and chandah then refuses the program by name.
3. **ast_nodes.py.** The dataclasses FuncDef, VarDef, While, If, Return, ExprStmt, BinOp, UnaryOp, Call, Index, Var, Num,
   StrLit and Param, made by `parse_source`. As given.
4. **mappings.py.** `OP_TO_SUTRAM`, `SUTRAM_TO_OP`, `ident_to_sutram`, `sutram_to_ident`: `ident_to_sutram("my_var")`
   gives `myयोजकvar`, and `OP_TO_SUTRAM["+"]` gives `योजय`. As given. Its keyword and type words are Hindawi's own.
5. **forward.py.** `sutram = program_to_sutram(preprocs, funcs, numeral_mode='katapayadi')` (or `'devanagari'`), with
   `expr_to_words` and `stmt_to_words` below it. As given.
6. **reverse.py.** **Correction:** `parse_sutram(sutram_text)` returns the Sanskrit C source as text, not
   `(preprocs, funcs)`.
7. **numerals.py.** `to_devanagari_digits("123")` gives `१२३`; `to_latin_digits` goes back. As given.
8. **katapayadi.py.** `encode_katapayadi("5")` gives `ङ`; `decode_katapayadi` goes back. As given.
9. **codec.py.** `enc, meta = codec.encode(src, numeral_mode='katapayadi', structure=None, apply_sandhi=False)`.
   **Correction:** `structure` is one of None, `samasa_line`, `samasa_full`, `chhandas_anushtubh`, `chhandas_gayatri`,
   `chhandas_trishtubh` and `chhandas_jagati`. `dec, base = codec.decode(enc, meta)` returns the Sanskrit C source and the
   base sutram. **Correction C2:** the given `ensure_compiles` did not compile: it replaced a fixed list of words and
   returned a binary-search result computed in Python, whatever the program. It now compiles and runs through Hindawi,
   returning `(host_c, output)`, and raises `RuntimeError` when Hindawi is not here or the program does not build.
10. **cli.py.** `s = c_to_sutram(src, numeral_mode='katapayadi', samasa_mode=None, apply_sandhi=True)`;
    **Correction:** `sutram_to_c(s)` returns Sanskrit C, not English C. `chhandas_to_c` and `samasta_to_c` as given. The
    `chandah` command is separate (above).
11. **sandhi_samasa.py.** `sutram_to_samasta(sutram_text, mode='line' or 'full', apply_sandhi=True)` and
    `samasta_to_sutram(comp, mode=..., known_identifiers=...)`. **Correction:** "bijective" holds with katapayadi
    numerals; with Devanagari numerals the compounds do not come back exactly (Measured, below).
12. **sandhi_panini.py.** `panini_join_two("नीचः", "स्थापय")` gives `नीचस्स्थापय`; `stage2_join("तत्", "लय")` gives
    `तलँय`; `panini_unsandhi` and `stage2_unsandhi` undo them. As given.
13. **chhandas.py.** `ch = format_anushtubh_bijective(sutram_text)`; `parse_chhandas_bijective(ch)` gives the sutram back.
    As given.
14. **true_chhandas.py.** `ch = format_true_chhandas(sutram_text, chhandas_type='anushtubh')`. **Correction:**
    `parse_true_chhandas(ch)` gives the sutram back; `strip_true_fillers(ch)` alone does not.
15. **library_spine.py.** `lib = LibrarySpine()`; `lib.declare('सङ्कलनम्', c_equivalent='accumulate',
    derived_from='सम्+कल')` returns `('accumulate', 'सम्+कल', False)`; `lib.resolve('सङ्कलनम्')` gives `accumulate`;
    an unknown word raises `LibraryError`. **Correction:** `list_core()` holds 30 verbs in the code, not the 32 that
    REGRESSION.md and the HTML manual state.
16. **`__init__.py`** (given as "init.py"). Marks the package.

The pipeline, as the given text describes it: `lex`, `parse_source`, `program_to_sutram`, then optionally
`sutram_to_samasta` or a chhandas layer, then back; or `codec.encode` and `codec.decode`. **Correction:** going back from
true chhandas is `parse_true_chhandas`, and the program that comes back is Sanskrit C, which Hindawi builds and runs.

## Coverage

v11 covers functions over `पूर्णाङ्क` (int) and `शून्य` (void), `यावत्` (while), `यदि` and `अन्यथा` (if, else),
`प्रत्यागम` (return), arrays and their initialisers, calls, `&` and `*`, `प्रारूप_लिख` (printf) with `%d`, `%s` and `\n`,
and `#अन्तर्भाव <stdio.h>`. It does not yet cover `प्रति` (for), `भङ्ग` (break), `अनुवर्त` (continue), `वर्ण` (char) and
the other types, declarations outside functions, other headers, or C++. In the Sanskrit GATE gallery of Hindawi 2026.10
(`docs/hindawi/samples/sanskrit`, 114 programs), v11 parses one: the binary search. The C++ program of the notebook stops
at its first class.

## Measured

The notebook's C program (the binary search), through every numeral mode, structure and sandhi choice, checked on the way
back (the base sutram and the program's parse tree): katapayadi numerals 13 of 13 combinations come back exactly;
Devanagari numerals 5 of 13. Built and run by Hindawi, the original and the program reverted from chhandas
(anushtubh, katapayadi, sandhi) both print `5 -1`.

| numerals | structure | sandhi | comes back |
|---|---|---|---|
| devanagari | none | off | yes |
| devanagari | samasa_line | off | no |
| devanagari | samasa_line | on | no |
| devanagari | samasa_full | off | no |
| devanagari | samasa_full | on | no |
| devanagari | chhandas_anushtubh | off | yes |
| devanagari | chhandas_anushtubh | on | no |
| devanagari | chhandas_gayatri | off | yes |
| devanagari | chhandas_gayatri | on | no |
| devanagari | chhandas_trishtubh | off | yes |
| devanagari | chhandas_trishtubh | on | no |
| devanagari | chhandas_jagati | off | yes |
| devanagari | chhandas_jagati | on | no |
| katapayadi | none | off | yes |
| katapayadi | samasa_line | off | yes |
| katapayadi | samasa_line | on | yes |
| katapayadi | samasa_full | off | yes |
| katapayadi | samasa_full | on | yes |
| katapayadi | chhandas_anushtubh | off | yes |
| katapayadi | chhandas_anushtubh | on | yes |
| katapayadi | chhandas_gayatri | off | yes |
| katapayadi | chhandas_gayatri | on | yes |
| katapayadi | chhandas_trishtubh | off | yes |
| katapayadi | chhandas_trishtubh | on | yes |
| katapayadi | chhandas_jagati | off | yes |
| katapayadi | chhandas_jagati | on | yes |

## The words, read from the code

Operators (`OP_TO_SUTRAM`):

| token | word |
|---|---|
| `=` | स्थापय |
| `+=` | योजयस्थापय |
| `-=` | वियोजयस्थापय |
| `*=` | गुणयस्थापय |
| `/=` | विभजस्थापय |
| `%=` | शेषस्थापय |
| `==` | समम् |
| `!=` | नसमम् |
| `<` | अल्पतरम् |
| `>` | अधिकतरम् |
| `<=` | अल्पतरंवासमम् |
| `>=` | अधिकतरंवासमम् |
| `+` | योजय |
| `-` | वियोजय |
| `*_bin` | गुणय |
| `/` | विभज |
| `%` | शेषम् |
| `!` | न |
| `&&` | च |
| `\|\|` | वा |
| `++` | वर्धय |
| `--` | क्षपय |
| `&_addr` | पता |
| `*_deref` | अन्तर्वस्तु |
| `->` | मध्ये |
| `.` | मध्ये |
| `::` | क्षेत्र |

Keywords and types are Hindawi's own, kept as written: अन्यथा, पूर्णाङ्क, प्रत्यागम, यदि, यावत्, शून्य. Headers:
`<stdio.h>` is मानकप्रवाह. Formats: `%d` प्रारूपपूर्णाङ्क, `%s` प्रारूपपाठ, `\n` नूतनपङ्क्ति.

## Where the HTML manual differs from the code

The HTML manual's word table, against v11's code (12 of 22 rows differ). Its word for `return`,
प्रत्यर्पय, is also not Hindawi's: Hindawi and the code both use प्रत्यागम.

| token | the HTML manual | v11's code | |
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
| `int` | पूर्णाङ्क | पूर्णाङ्क | agrees |
| `return` | प्रत्यर्पय | प्रत्यागम | differs |
| `if` | यदि | यदि | agrees |
| `else` | अन्यथा | अन्यथा | agrees |
| `while` | यावत् | यावत् | agrees |
| `break` | विरम | none: v11 has no break | differs |
| `;` | विराम | none: v11 marks structure with its own words instead | differs |
| `,` | अल्पविराम | none: v11 marks structure with its own words instead | differs |
| `{` | प्रारम्भ | none: v11 marks structure with its own words instead | differs |
| `}` | अवसान | none: v11 marks structure with its own words instead | differs |
