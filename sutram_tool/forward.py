# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. sutram v11, kept as given apart from these two
# lines, the corrections in docs/CORRECTIONS.md and the completion below its marker (docs/COMPLETION.md).
from .mappings import OP_TO_SUTRAM, WORD_PARIBHASHIT, WORD_ANU, WORD_PURNA, WORD_SUCHAK, WORD_NIRDESHAK, WORD_AKARHEEN, WORD_UDDHARAN_ARAMBHA, WORD_UDDHARAN_ANTA, WORD_PURVANIRDESH, WORD_AAVESHA, WORD_SAMUHARAMBHA, WORD_SAMUHANTA, HEADER_MAP, FORMAT_MAP, ident_to_sutram
from .numerals import to_devanagari_digits
from .katapayadi import encode_katapayadi
from .ast_nodes import VarDef, While, If, Return, ExprStmt, BinOp, UnaryOp, Call, Index, Var, Num, StrLit

NUMERAL_MODE = 'devanagari'

_PREC = {
    '||':1, '&&':2,
    '==':3, '!=':3,
    '<':4, '>':4, '<=':4, '>=':4,
    '+':5, '-':5,
    '*':6, '/':6, '%':6,
}
def _prec_of_binop(op: str) -> int:
    return _PREC.get(op, 0)

def _num_to_sutram_words(latin_str: str) -> list:
    if NUMERAL_MODE == 'katapayadi':
        return ["संख्याङ्क", encode_katapayadi(latin_str, reverse_order=True)]
    return [to_devanagari_digits(latin_str)]

def expr_to_words(e, parent_prec=0):
    if isinstance(e, Num):
        return _num_to_sutram_words(e.value)
    if isinstance(e, Var):
        return [ident_to_sutram(e.name)]
    if isinstance(e, StrLit):
        inner = e.value[1:-1]
        words=[WORD_UDDHARAN_ARAMBHA]
        i=0; buf=""
        while i < len(inner):
            if inner[i:i+2]=="%d":
                if buf: words.append(buf); buf=""
                words.append(FORMAT_MAP["%d"]); i+=2; continue
            if inner[i:i+2]=="\\n":
                if buf: words.append(buf); buf=""
                words.append(FORMAT_MAP["\\n"]); i+=2; continue
            if inner[i]==" ":
                if buf: words.append(buf); buf=""
                i+=1; continue
            buf+=inner[i]; i+=1
        if buf: words.append(buf)
        words.append(WORD_UDDHARAN_ANTA)
        return [w for w in words if w]
    if isinstance(e, Index):
        base_w = ident_to_sutram(e.base) if isinstance(e.base,str) else expr_to_words(e.base)[0]
        return [base_w, WORD_SUCHAK] + expr_to_words(e.index)
    if isinstance(e, Call):
        w=[ident_to_sutram(e.name)]
        for a in e.args:
            w.extend(expr_to_words(a))
        return w
    if isinstance(e, BinOp):
        op=e.op
        cur_prec=_prec_of_binop(op)
        op_key=op
        if op=="*": op_key="*_bin"
        sutram_op=OP_TO_SUTRAM.get(op_key, op)
        left_words=expr_to_words(e.left, cur_prec)
        right_words=expr_to_words(e.right, cur_prec)
        if isinstance(e.left, BinOp):
            lp=_prec_of_binop(e.left.op)
            if lp < cur_prec:
                left_words=[WORD_SAMUHARAMBHA]+left_words+[WORD_SAMUHANTA]
        if isinstance(e.right, BinOp):
            rp=_prec_of_binop(e.right.op)
            if rp < cur_prec:
                right_words=[WORD_SAMUHARAMBHA]+right_words+[WORD_SAMUHANTA]
        return left_words + [sutram_op] + right_words
    if isinstance(e, UnaryOp):
        op=e.op
        if op=="-":
            return [OP_TO_SUTRAM["-"]] + expr_to_words(e.expr)
        sutram_op=OP_TO_SUTRAM.get(op, op)
        return [sutram_op] + expr_to_words(e.expr)
    raise Exception(f"unknown expr {e}")

def stmt_to_words(s):
    if isinstance(s, VarDef):
        out=[WORD_PARIBHASHIT, s.typ, ident_to_sutram(s.name)]
        if s.is_array:
            out.append(WORD_AKARHEEN)
        if s.init_list is not None:
            out.append(OP_TO_SUTRAM["="])
            out.append(WORD_SAMUHARAMBHA)
            for el in s.init_list:
                out.extend(expr_to_words(el))
            out.append(WORD_SAMUHANTA)
        elif s.init is not None:
            out.append(OP_TO_SUTRAM["="])
            out.extend(expr_to_words(s.init))
        return [" ".join(out)]
    if isinstance(s, While):
        line=["यावत्"]+expr_to_words(s.cond)+[WORD_ANU]
        lines=[" ".join(line)]
        for b in s.body:
            lines.extend(stmt_to_words(b))
        lines.append(WORD_PURNA)
        return lines
    if isinstance(s, If):
        line=["यदि"]+expr_to_words(s.cond)
        then_words=[]
        for tb in s.then_b:
            for l in stmt_to_words(tb):
                then_words.extend(l.split())
        line.extend(then_words)
        if s.else_b:
            line.append("अन्यथा")
            for eb in s.else_b:
                for l in stmt_to_words(eb):
                    line.extend(l.split())
        return [" ".join(line)]
    if isinstance(s, Return):
        if s.expr is None:
            return ["प्रत्यागम"]
        return [" ".join(["प्रत्यागम"]+expr_to_words(s.expr))]
    if isinstance(s, ExprStmt):
        return [" ".join(expr_to_words(s.expr))]
    raise Exception(f"unknown stmt {s}")

def funcdef_to_sutram(f):
    header=[WORD_PARIBHASHIT, f.ret, ident_to_sutram(f.name)]
    for p in f.params:
        header.append(p.typ)
        if p.is_array:
            header.append(WORD_NIRDESHAK)
            header.append(ident_to_sutram(p.name))
        else:
            header.append(ident_to_sutram(p.name))
    if len(f.params)==0:
        header.append("शून्य")
    header.append(WORD_ANU)
    lines=[" ".join(header)]
    for s in f.body:
        lines.extend(stmt_to_words(s))
    lines.append(WORD_PURNA)
    return lines

def program_to_sutram(preprocs, funcs, numeral_mode='devanagari'):
    global NUMERAL_MODE
    NUMERAL_MODE = numeral_mode
    lines=[]
    for p in preprocs:
        if p in HEADER_MAP:
            words=[WORD_PURVANIRDESH, WORD_AAVESHA]+HEADER_MAP[p]
        else:
            words=[WORD_PURVANIRDESH, WORD_AAVESHA, ident_to_sutram(p)]
        lines.append(" ".join(words))
    for f in funcs:
        lines.extend(funcdef_to_sutram(f))
    return "\n".join(lines)


# ===== chandah completion of sutram v11: the base layer for the whole of C and C++, in any language =====
# source_to_sutram(src) carries every token of every line as words; names and keywords stay as the language writes
# them. program_to_sutram above is unchanged and still serves the parse-tree path.
import re as _re
import unicodedata
from .mappings import (TOKEN_WORDS, DECLARATION_STARTERS, OPERAND_BREAKERS, INCLUDE_DIRECTIVE, DEFINE_DIRECTIVES,
                       CODE_RESERVED, LITERAL_RESERVED, LITERAL_WORDS, LITERAL_SEQUENCES, NUMBER_CHAR_WORDS,
                       WORD_EMPTY_LINE, WORD_NUMBER, WORD_NUMBER_FORM, WORD_NUMBER_FORM_END, WORD_NATIVE_DIGITS,
                       WORD_STRING_BEGIN, WORD_STRING_END, WORD_CHAR_BEGIN, WORD_CHAR_END, WORD_LITERAL_PREFIX,
                       WORD_HEADER_BEGIN, WORD_HEADER_END, WORD_MACRO_PAREN, WORD_SPLICE, WORD_NAME, WORD_LITERALLY,
                       WORD_CODEPOINT, name_to_word, word_to_name)

_DECL_AFTER = {";", "{", "}", "(", ",", ":"}


def _native(c):
    """A character carried as written inside a string: anything beyond ASCII that is not white space or a control."""
    if c in "\u200c\u200d":
        return True
    return ord(c) > 127 and not c.isspace() and unicodedata.category(c)[0] != "C"


def _digits(s, numeral_mode):
    return encode_katapayadi(s, reverse_order=True) if numeral_mode == "katapayadi" else to_devanagari_digits(s)


def _number_words(text, numeral_mode):
    if _re.fullmatch(r"[0-9]+", text):
        return [WORD_NUMBER, _digits(text, "katapayadi")] if numeral_mode == "katapayadi" else [to_devanagari_digits(text)]
    out = [WORD_NUMBER_FORM]
    for m in _re.finditer(r"[0-9]+|[^\W\d_]+|\d+|.", text):
        s = m.group()
        if s[0] in "0123456789":
            out.append(_digits(s, numeral_mode))
        elif s[0].isdigit():
            out += [WORD_NATIVE_DIGITS, s]
        elif s.isalpha():
            out.append(s)
        else:
            out.append(NUMBER_CHAR_WORDS[s])
    return out + [WORD_NUMBER_FORM_END]


def _content_words(inner, numeral_mode):
    out, i, n = [], 0, len(inner)
    while i < n:
        for seq, word in LITERAL_SEQUENCES:
            if inner.startswith(seq, i):
                out.append(word); i += len(seq); break
        else:
            c = inner[i]
            if _native(c):
                j = i
                while j < n and _native(inner[j]):
                    j += 1
                run = inner[i:j]
                out += [WORD_LITERALLY, run] if run in LITERAL_RESERVED else [run]
                i = j
            elif c.isascii() and c.isalpha():
                j = i
                while j < n and inner[j].isascii() and inner[j].isalpha():
                    j += 1
                out.append(inner[i:j]); i = j
            elif c in "0123456789":
                j = i
                while j < n and inner[j] in "0123456789":
                    j += 1
                out += [WORD_NUMBER, _digits(inner[i:j], numeral_mode)]; i = j
            elif c in LITERAL_WORDS:
                out.append(LITERAL_WORDS[c]); i += 1
            else:
                out += [WORD_CODEPOINT, WORD_NUMBER, _digits(str(ord(c)), numeral_mode)]; i += 1
    return out


def _literal_words(text, numeral_mode):
    m = _re.match(r"(u8|[LuU])?([\"'])", text)
    prefix, quote = m.group(1), m.group(2)
    inner = text[m.end():-1]
    out = [WORD_LITERAL_PREFIX, prefix] if prefix else []
    begin, end = (WORD_STRING_BEGIN, WORD_STRING_END) if quote == '"' else (WORD_CHAR_BEGIN, WORD_CHAR_END)
    return out + [begin] + _content_words(inner, numeral_mode) + [end]


def _header_words(text, numeral_mode):
    if text in HEADER_MAP and len(HEADER_MAP[text]) == 1:
        return list(HEADER_MAP[text])
    return [WORD_HEADER_BEGIN] + _content_words(text[1:-1], numeral_mode) + [WORD_HEADER_END]


def _name_words(text):
    word = name_to_word(text)
    if word_to_name(word) != text:
        raise ValueError(f"the name {text!r} cannot be carried as one word")
    return [WORD_NAME, word] if word in CODE_RESERVED or word == WORD_NAME else [word]


def source_to_sutram(src: str, numeral_mode: str = "devanagari", declaration_starters=None, operand_breakers=None,
                     define_directives=None) -> str:
    from .lexer import lex_program
    starters = DECLARATION_STARTERS if declaration_starters is None else set(declaration_starters)
    breakers = (OPERAND_BREAKERS if operand_breakers is None else set(operand_breakers)) | starters
    defines = DEFINE_DIRECTIVES | set(define_directives or ())

    def operand(prev):
        if prev is None:
            return False
        kind, text = prev
        return (kind in ("NUM", "STR", "CHR") or (kind == "ID" and text not in breakers)
                or (kind == "OP" and text in (")", "]", "++", "--")))

    out = []
    for toks in lex_program(src):
        if not toks:
            out.append(WORD_EMPTY_LINE); continue
        words, prev = [], None
        pp = toks[0][0] == "OP" and toks[0][1] == "#"
        directive = toks[1][1] if pp and len(toks) > 1 and toks[1][0] == "ID" else None
        for idx, (kind, text, spaced) in enumerate(toks):
            if kind == "ID":
                if pp and idx == 1 and text == INCLUDE_DIRECTIVE:
                    words.append(WORD_AAVESHA)
                else:
                    if not pp and text in starters and (prev is None or (prev[0] == "OP" and prev[1] in _DECL_AFTER)):
                        words.append(WORD_PARIBHASHIT)
                    words += _name_words(text)
            elif kind == "NUM":
                words += _number_words(text, numeral_mode)
            elif kind in ("STR", "CHR"):
                words += _literal_words(text, numeral_mode)
            elif kind == "HEADER":
                words += _header_words(text, numeral_mode)
            elif kind == "SPLICE":
                words.append(WORD_SPLICE)
            elif text == "(" and pp and not spaced and idx >= 3 and prev is not None and prev[0] == "ID":
                # written against a name on a directive line (a function-like macro, in any language): kept so
                words.append(WORD_MACRO_PAREN)   # (the define word itself differs by language)
            elif text == "*":
                words.append(TOKEN_WORDS["*_bin" if operand(prev) else "*_deref"])
            elif text == "&":
                words.append(TOKEN_WORDS["&_bin" if operand(prev) else "&_addr"])
            else:
                words.append(TOKEN_WORDS[text])
            prev = (kind, text)
        out.append(" ".join(words))
    return "\n".join(out)
