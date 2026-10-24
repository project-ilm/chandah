<!-- Meta AI's note on sutram v11, as relayed by Abhishek Choudhary on 23 October 2026, recorded as given (master contract C47). Where chandah stands on each point: docs/MANUAL.md. -->

To Claude: You have restore_sutram_v11.py. It is a self-extracting Python restore, not a compiler.

What v11 IS:
Front-end only. Sanskrit C -> Sutram (words-only) -> Sanskrit C. Bijective.
It does NOT compile. Compilation is done by the user's existing Sanskrit C backend, out of scope.

What v11 IS NOT:
It is not supposed to output compilable C directly. The Sutram output is NOT C.

Exact commands to run:

python3 restore_sutram_v11.py
   Restores to sutram_tool_restore/ with 16 files under sutram_tool/.

ls sutram_tool_restore/sutram_tool/
   You must see 16 .py files: codec.py, mappings.py, forward.py, reverse.py, etc.

Run this:
import sys
sys.path.insert(0, 'sutram_tool_restore')
from sutram_tool import codec
src = open('sutram_tool_restore/sutram_tool/../example_src.txt', encoding='utf-8').read()
if example_src.txt not in restore, use this minimal:
src = "पूर्णाङ्क मुख्य() { पूर्णाङ्क अ = 1; }"
enc, meta = codec.encode(src, numeral_mode='katapayadi', structure=None, apply_sandhi=False)
print(enc[:500])
dec_c, dec_s = codec.decode(enc, meta)
print("sutram roundtrip:", dec_s == meta['base_sutram'])
print("has symbols in enc:", any(c in enc for c in '{}();'))
Expected:
enc contains only Devanagari words, spaces, newlines. No { } ( ) ;.
sutram roundtrip: True
has symbols in enc: False

About keywords complaint:
Input keywords like पूर्णाङ्क, यावत्, यदि are the user's Sanskrit C dialect. We did not invent them. They are in example_src.txt.
Output words like परिभाषित (= declaration marker), स्थापय (= =), योजय (= +) are defined in sutram_tool/mappings.py as OP_TO_SUTRAM. This is intentional.
Requirement from user: "final code containing only words, spaces and newlines and no symbols". Therefore = MUST become a word. ;, {, } MUST become words or line breaks. Added words like परिभाषित and अणु are bijective markers so decode can reverse exactly. Without them, reverse is ambiguous.
Do NOT try to compile enc with gcc. Compile dec_c, which is Sanskrit C again.

If you check mappings.py, you will see the full table. This is not a keyword mismatch, it is two layers: Layer1 Sanskrit C (compilable), Layer2 Sutram (words-only, not compilable, decodable).
