# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these two lines and the corrections recorded in docs/CORRECTIONS.md.
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
