<!-- Meta AI's "Complete Requirements Set for Sutram v11", as relayed by Abhishek Choudhary on 23 October 2026, recorded as given (master contract C47). How chandah meets each: docs/MANUAL.md. -->

Complete Requirements Set for Sutram v11 - give this to Claude:

1. Purpose
Front-end pre-processor. Converts Sanskrit C to Sutram and back. Does not compile. Backend Sanskrit C compiler is out of scope and unchanged.

2. Input
Sanskrit C source. Example:
पूर्णाङ्क द्विमान_अन्वेषणम्(पूर्णाङ्क मानानि[], पूर्णाङ्क गणनम्) {
  पूर्णाङ्क नीचः = 0;
}
Keywords are user-defined Sanskrit C dialect: पूर्णाङ्क = int, यावत् = while, यदि = if, etc.

3. Output - Sutram
Only words, spaces, newlines. No symbols: no { } ( ) ; , [ ] < > = + - * /.
Every symbol mapped to a single word via mappings.py OP_TO_SUTRAM. E.g. = -> स्थापय, + -> योजय, == -> समम्.
Every declaration marked with परिभाषित, block end with अणु.
Bijective: decode(encode(src)) must recover sutram exactly. dec_s == meta['base_sutram'] must be True.

4. Numerals
Two modes:
devanagari: keep Devanagari digits
katapayadi: replace all standalone numbers with Katapayadi words. E.g. 0 -> न, 1 -> क. Traditional system pandits recognize. Must be reversible.

5. Structure options
None: plain sutram lines
samasa_line, samasa_full: apply samasa compounding, bijective
chhandas_anushtubh, gayatri, etc.: format into approx 8-syllable padas with पङ्क्त्यन्त markers. Bijective via format_anushtubh_bijective. Note: approximate syllable count, not strict laghu/guru validation.

6. Sandhi
Optional, applied AFTER structure, never before. Must be bijective. sandhi_panini.py implements Paninian rules with explicit rule list.

7. Rule-based
No neural guess. All transformations are explicit tables in mappings.py, katapayadi.py, sandhi_panini.py. Function parameter arrays must be handled explicitly.

8. Pandit-readable
Output must be readable by Sanskrit pandit with no CS background. Use traditional terms.

9. Modules - 16 files
codec.py, forward.py, reverse.py, parser.py, lexer.py, mappings.py, katapayadi.py, numerals.py, sandhi_panini.py, sandhi_samasa.py, chhandas.py, true_chhandas.py, library_spine.py, ast_nodes.py, cli.py, **init**.py

10. Acceptance tests
python3 restore_sutram_v11.py
PYTHONPATH=sutram_tool_restore python3 -c "
from sutram_tool import codec
src=open('example_src.txt',encoding='utf-8').read()
enc,meta=codec.encode(src,numeral_mode='katapayadi',structure=None,apply_sandhi=False)
assert all(c not in enc for c in '{}();'), 'symbols remain'
dec_c,dec_s=codec.decode(enc,meta)
assert dec_s==meta['base_sutram'], 'sutram not bijective'
print('PASS')
"
11. Ensure compilation succeeds across all paths
