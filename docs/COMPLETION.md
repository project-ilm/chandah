# The completion of sutram v11

© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI.

v11 parsed a small part of Sanskrit C: in Hindawi's Sanskrit gallery it covered one program of 114. The author's
instructions of 23 and 24 October 2026 were to complete it, so that every sample can be raised to chandah, lowered back
to compilable form and built, on every path, in every language Hindawi supports, with short words. The completion does that without touching v11's text: each block is written
below a marker at the end of the module it completes (`# ===== chandah completion of sutram v11 ...`), the files stay the
same 16, and `ops/from_given.py` makes `sutram_tool/` from the given restore script, the two corrections and these blocks
(`ops/completion/`), which the gate checks byte for byte (V02).

| module | what the completion adds |
|---|---|
| `mappings.py` | a short word for every token of C and C++ (the chosen words shortened; च, न and वा as they were), the markers, the words for characters inside strings and numbers, Hindawi's declaration keywords (retrieved from its tables), and names carried as one word that always comes back |
| `lexer.py` | `lex_program`: every token of C and C++ by physical line, names in any script, strings, characters, numbers of every form, header names, function-like macros and line splices; comments dropped, their lines kept |
| `forward.py` | `source_to_sutram`: the base layer, every token of every line as words; v11's words wherever v11 had them; परिभाषित before every declaration |
| `reverse.py` | `sutram_to_source`: back to the compilable program, every token, one line per sutram line, indented by its blocks |
| `sandhi_samasa.py` | compounds formed only where the splitter brings back exactly the words they were made of; each compound split on its own |
| `codec.py` | `encode` and `decode` on the complete base layer, in v11's order: structure, then sandhi |
| `cli.py` | `c_to_sutram` and `sutram_to_c` on the complete base layer |

v11's parse-tree path (`parse_source`, `program_to_sutram`, `parse_sutram`) remains as given for the programs it covers.
The words the completion adds are listed in docs/MANUAL.md for the author to confirm or change; they are data in
`mappings.py`, and a change there is a recorded change like any other.
