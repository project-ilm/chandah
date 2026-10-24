

# ===== chandah completion of sutram v11 (23 October 2026): a lexer for the whole of Sanskrit C and C++ =====
# lex_program(src) returns the program's physical lines, each a list of (kind, text, spaced) tokens; comments are dropped
# but their lines kept, so line numbers survive. kind is ID, NUM, STR, CHR, OP, HEADER or SPLICE; spaced says whether
# white space came before the token on its line. v11's lex() above is unchanged.
_FULL_OPS = [">>=", "<<=", "...", "->*", "->", "++", "--", "<<", ">>", "<=", ">=", "==", "!=", "&&", "||", "+=", "-=",
             "*=", "/=", "%=", "&=", "|=", "^=", "::", ".*", "+", "-", "*", "/", "%", "=", "<", ">", "!", "&", "|", "^",
             "~", "?", ":", ";", ",", ".", "(", ")", "{", "}", "[", "]", "#"]
_ID_START = "A-Za-z_\u0900-\u0963\u0970-\u097F"
_ID_REST = "A-Za-z0-9_\u0900-\u0963\u0966-\u096F\u0970-\u097F\u200c\u200d"
_FULL_RE = re.compile("|".join([
    r"(?P<NL>\n)", r"(?P<SPLICE>\\\n)", r"(?P<WS>[ \t\r\f\v]+)", r"(?P<COMMENT>/\*.*?\*/|//[^\n]*)",
    r'(?P<STR>(?:u8|[LuU])?"(?:[^"\\\n]|\\.)*")', r"(?P<CHR>(?:u8|[LuU])?'(?:[^'\\\n]|\\.)*')",
    r"(?P<NUM>\.?[0-9\u0966-\u096F](?:[eEpP][+-]|[0-9\u0966-\u096FA-Za-z_.])*)",
    rf"(?P<ID>[{_ID_START}][{_ID_REST}]*)",
    "(?P<OP>" + "|".join(re.escape(o) for o in _FULL_OPS) + ")",
]), re.S)
_HEADER_RE = re.compile(r"<[^>\n]*>")


def lex_program(src: str):
    lines, cur, i, n = [], [], 0, len(src)
    spaced, include_next = True, False
    while i < n:
        if include_next:
            m = _HEADER_RE.match(src, i)
            if m:
                cur.append(("HEADER", m.group(), spaced)); i = m.end(); spaced = False; include_next = False; continue
            if not src[i].isspace():
                include_next = False
        m = _FULL_RE.match(src, i)
        if not m:
            line = src.count("\n", 0, i) + 1
            raise ValueError(f"line {line}: chandah cannot read the character {src[i]!r} here")
        kind, text = m.lastgroup, m.group()
        i = m.end()
        if kind == "NL":
            lines.append(cur); cur = []; spaced = True; include_next = False; continue
        if kind == "WS":
            spaced = True; continue
        if kind == "COMMENT":
            for _ in range(text.count("\n")):
                lines.append(cur); cur = []
            spaced = True; continue
        if kind == "SPLICE":
            cur.append(("SPLICE", "\\", spaced)); lines.append(cur); cur = []; spaced = True; continue
        cur.append((kind, text, spaced)); spaced = False
        if kind == "ID" and len(cur) == 2 and cur[0][1] == "#" and text in ("अन्तर्भाव", "include"):
            include_next = True
    if cur or not src.endswith("\n"):
        lines.append(cur)
    return lines
