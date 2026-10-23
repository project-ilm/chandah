<!-- The usage text Meta AI gave for sutram v11, as pasted by Abhishek Choudhary on 23 October 2026, recorded as given. The corrected manual is docs/MANUAL.md. -->

Understood. No HTML, no assumptions about your system. Just file by file usage for the 16 files in v11. Copy from here.

Setup
import sys
sys.path.insert(0, '/path/to/restored')  # folder containing sutram_tool/
1. lexer.py
Tokenizes C-like source.
from sutram_tool.lexer import lex
toks = lex(src)  # src: str, returns list of tokens
2. parser.py
Parses tokens to AST.
from sutram_tool.parser import parse_source
preprocs, funcs = parse_source(src)  # preprocs: list, funcs: list[FuncDef]
3. ast_nodes.py
Dataclasses: FuncDef, VarDef, While, If, Return, ExprStmt, BinOp, UnaryOp, Call, Index, Var, Num, StrLit, Param
You don't call directly, they come from parse_source.

4. mappings.py
Core char to word tables.
from sutram_tool.mappings import OP_TO_SUTRAM, SUTRAM_TO_OP, ident_to_sutram, sutram_to_ident
ident_to_sutram("my_var")  # -> "myयोजकvar"
sutram_to_ident("myयोजकvar")  # -> "my_var"
OP_TO_SUTRAM["+"]  # -> "योजय"
5. forward.py
AST to sutram words.
from sutram_tool.forward import program_to_sutram
sutram = program_to_sutram(preprocs, funcs, numeral_mode='katapayadi')  # or 'devanagari'
lower level:
from sutram_tool.forward import expr_to_words, stmt_to_words
6. reverse.py
Sutram words back to AST.
from sutram_tool.reverse import parse_sutram
preprocs, funcs = parse_sutram(sutram_text)
7. numerals.py
Devanagari digit conversion.
from sutram_tool.numerals import to_devanagari_digits, to_latin_digits
to_devanagari_digits("123")  # -> "१२३"
8. katapayadi.py
Traditional Katapayadi numeral encoding.
from sutram_tool.katapayadi import encode_katapayadi, decode_katapayadi
encode_katapayadi("5")  # -> Sanskrit word
decode_katapayadi(word)
9. codec.py
High level encode/decode. Use this for end to end.
from sutram_tool import codec
enc, meta = codec.encode(src, numeral_mode='katapayadi', structure=None, apply_sandhi=False)
structure: None, 'samasa_line', 'samasa_full', 'chhandas_anushtubh'
meta contains 'base_sutram' for regression

dec_c, dec_sutram = codec.decode(enc, meta)
codec.ensure_compiles(dec_c)  # raises if not compilable, returns True
10. cli.py
Convenience wrappers.
from sutram_tool.cli import c_to_sutram, sutram_to_c, chhandas_to_c, samasta_to_c
s = c_to_sutram(src, numeral_mode='katapayadi', samasa_mode=None, apply_sandhi=True)
c = sutram_to_c(s)
11. sandhi_samasa.py
Samasa compounding, bijective.
from sutram_tool.sandhi_samasa import sutram_to_samasta, samasta_to_sutram
comp = sutram_to_samasta(sutram_text, mode='line', apply_sandhi=True)  # mode: 'line' or 'full'
orig = samasta_to_sutram(comp, mode='line', known_identifiers=set())
12. sandhi_panini.py
Staged Paninian sandhi, bijective via markers.
from sutram_tool.sandhi_panini import panini_join_two, panini_unsandhi, stage2_join, stage2_unsandhi
panini_join_two("नीचः", "स्थापय")  # visarga + ach stage1
stage2_join("तत्", "लय")  # hal/rutva/anusvara stage2
13. chhandas.py
Basic Anushtubh formatting.
from sutram_tool.chhandas import format_anushtubh_bijective, parse_chhandas_bijective
ch = format_anushtubh_bijective(sutram_text)
sutram = parse_chhandas_bijective(ch)
14. true_chhandas.py
True chhandas with padapurana fillers.
from sutram_tool.true_chhandas import format_true_chhandas, strip_true_fillers, parse_true_chhandas
ch = format_true_chhandas(sutram_text, chhandas_type='anushtubh')
sutram = strip_true_fillers(ch)  # or parse_true_chhandas(ch)
15. library_spine.py
Rule based library declaration. Additive, does not touch codec.
from sutram_tool.library_spine import LibrarySpine, LibraryError
lib = LibrarySpine()
lib.declare('सङ्कलनम्', c_equivalent='accumulate', derived_from='सम्+कल')
lib.resolve('सङ्कलनम्')  # -> 'accumulate'
lib.list_core()  # dict of foundational
lib.list_derived()
raises LibraryError on unknown or ambiguous
16. init.py
Empty, marks package.

Typical pipeline you can implement:
lex -> parse_source -> program_to_sutram -> optional sutram_to_samasta / format_true_chhandas -> parse_sutram to go back. Or just use codec.encode / codec.decode.
