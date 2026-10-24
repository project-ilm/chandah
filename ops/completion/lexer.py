

# ===== chandah completion of sutram v11: a lexer for the whole of C and C++, in any language Hindawi supports =====
# lex_program(src) returns the program's physical lines, each a list of (kind, text, spaced) tokens; comments are dropped
# but their lines kept, so line numbers survive. Names may be written in any script. kind is ID, NUM, STR, CHR, OP,
# HEADER or SPLICE; spaced says whether white space came before the token on its line. v11's lex() above is unchanged.
import unicodedata as _ud


def _class(pred):
    ranges, start = [], None
    for cp in range(0x10000):
        ok = pred(chr(cp))
        if ok and start is None:
            start = cp
        elif not ok and start is not None:
            ranges.append((start, cp - 1)); start = None
    if start is not None:
        ranges.append((start, 0xFFFF))
    return "".join(re.escape(chr(a)) if a == b else re.escape(chr(a)) + "-" + re.escape(chr(b)) for a, b in ranges)


_ID_START = _class(lambda c: c == "_" or _ud.category(c)[0] in "LM")
_ID_REST = _class(lambda c: c in "_\u200c\u200d" or _ud.category(c)[0] in "LM" or _ud.category(c) == "Nd")
_FULL_OPS = [">>=", "<<=", "...", "->*", "->", "++", "--", "<<", ">>", "<=", ">=", "==", "!=", "&&", "||", "+=", "-=",
             "*=", "/=", "%=", "&=", "|=", "^=", "::", ".*", "##", "+", "-", "*", "/", "%", "=", "<", ">", "!", "&", "|",
             "^", "~", "?", ":", ";", ",", ".", "(", ")", "{", "}", "[", "]", "#"]
_FULL_RE = re.compile("|".join([
    r"(?P<NL>\n)", r"(?P<SPLICE>\\\n)", r"(?P<WS>[ \t\r\f\v]+)", r"(?P<COMMENT>/\*.*?\*/|//[^\n]*)",
    r'(?P<STR>(?:u8|[LuU])?"(?:[^"\\\n]|\\.)*")', r"(?P<CHR>(?:u8|[LuU])?'(?:[^'\\\n]|\\.)*')",
    r"(?P<NUM>\.?\d(?:[eEpP][+-]|[^\W_]|[_.])*)",
    f"(?P<ID>[{_ID_START}][{_ID_REST}]*)",
    "(?P<OP>" + "|".join(re.escape(o) for o in _FULL_OPS) + ")",
]), re.S)
_HEADER_RE = re.compile(r"<[^>\n]*>")


def lex_program(src: str):
    lines, cur, i, n = [], [], 0, len(src)
    spaced, header_next = True, False
    while i < n:
        if header_next:
            m = _HEADER_RE.match(src, i)
            if m:
                cur.append(("HEADER", m.group(), spaced)); i = m.end(); spaced = False; header_next = False; continue
            if not src[i].isspace():
                header_next = False
        m = _FULL_RE.match(src, i)
        if not m:
            line = src.count("\n", 0, i) + 1
            raise ValueError(f"line {line}: chandah cannot read the character {src[i]!r} here")
        kind, text = m.lastgroup, m.group()
        i = m.end()
        if kind == "NL":
            lines.append(cur); cur = []; spaced = True; header_next = False; continue
        if kind == "WS":
            spaced = True; continue
        if kind == "COMMENT":
            for _ in range(text.count("\n")):
                lines.append(cur); cur = []
            spaced = True; continue
        if kind == "SPLICE":
            cur.append(("SPLICE", "\\", spaced)); lines.append(cur); cur = []; spaced = True; continue
        cur.append((kind, text, spaced)); spaced = False
        # #include <name> in any language: a header name only ever comes first after the directive's word
        if kind == "ID" and len(cur) == 2 and cur[0][1] == "#":
            header_next = True
    if cur or not src.endswith("\n"):
        lines.append(cur)
    return lines
