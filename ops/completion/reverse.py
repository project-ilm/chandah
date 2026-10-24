

# ===== chandah completion of sutram v11: from the complete base layer back to compilable source =====
# sutram_to_source(sutram) returns compilable C or C++ in the program's own language: every token back, one source
# line per sutram line, indented by its blocks. It needs nothing but the text. parse_sutram above is unchanged.
from .mappings import (WORD_TO_TOKEN, WORD_TO_LITERAL, NUMBER_CHAR_WORDS, HEADER_WORD_TO_NAME, WORD_EMPTY_LINE,
                       WORD_NUMBER, WORD_NUMBER_FORM, WORD_NUMBER_FORM_END, WORD_NATIVE_DIGITS, WORD_STRING_BEGIN,
                       WORD_STRING_END, WORD_CHAR_BEGIN, WORD_CHAR_END, WORD_LITERAL_PREFIX, WORD_HEADER_BEGIN,
                       WORD_HEADER_END, WORD_MACRO_PAREN, WORD_SPLICE, WORD_NAME, WORD_LITERALLY, WORD_CODEPOINT,
                       WORD_PARIBHASHIT, WORD_AAVESHA, INCLUDE_DIRECTIVE, word_to_name)

_NUMBER_WORD_TO_CHAR = {w: c for c, w in NUMBER_CHAR_WORDS.items()}


def _is_deva_digits(w):
    return bool(w) and all("\u0966" <= c <= "\u096F" for c in w)


def _digits_back(w):
    return to_latin_digits(w) if _is_deva_digits(w) else decode_katapayadi(w, reverse_order=True)


def _content_back(ws, i, end):
    out = []
    while ws[i] != end:
        w = ws[i]
        if w == WORD_LITERALLY:
            out.append(ws[i + 1]); i += 2
        elif w == WORD_NUMBER:
            out.append(_digits_back(ws[i + 1])); i += 2
        elif w == WORD_CODEPOINT:
            out.append(chr(int(_digits_back(ws[i + 2])))); i += 3
        elif w in WORD_TO_LITERAL:
            out.append(WORD_TO_LITERAL[w]); i += 1
        else:
            out.append(w); i += 1
    return "".join(out), i + 1


def _number_back(ws, i):
    out = []
    while ws[i] != WORD_NUMBER_FORM_END:
        w = ws[i]
        if w == WORD_NATIVE_DIGITS:
            out.append(ws[i + 1]); i += 2; continue
        if w in _NUMBER_WORD_TO_CHAR:
            out.append(_NUMBER_WORD_TO_CHAR[w])
        elif w.isascii() or (w.isalpha() and not _is_deva_digits(w) and not all("\u0915" <= c <= "\u0939" for c in w)):
            out.append(w)
        else:
            out.append(_digits_back(w))
        i += 1
    return "".join(out), i + 1


def sutram_to_tokens(sutram: str):
    lines = []
    for raw in sutram.split("\n"):
        ws = raw.split()
        if ws == [WORD_EMPTY_LINE]:
            lines.append([]); continue
        toks, i, prefix = [], 0, ""
        while i < len(ws):
            w = ws[i]
            if w == WORD_PARIBHASHIT:
                i += 1
            elif w == WORD_NAME:
                toks.append(("ID", word_to_name(ws[i + 1]))); i += 2
            elif w == WORD_NUMBER:
                toks.append(("NUM", _digits_back(ws[i + 1]))); i += 2
            elif _is_deva_digits(w):
                toks.append(("NUM", to_latin_digits(w))); i += 1
            elif w == WORD_NUMBER_FORM:
                text, i = _number_back(ws, i + 1); toks.append(("NUM", text))
            elif w == WORD_LITERAL_PREFIX:
                prefix = ws[i + 1]; i += 2
            elif w == WORD_STRING_BEGIN:
                text, i = _content_back(ws, i + 1, WORD_STRING_END); toks.append(("STR", prefix + '"' + text + '"')); prefix = ""
            elif w == WORD_CHAR_BEGIN:
                text, i = _content_back(ws, i + 1, WORD_CHAR_END); toks.append(("CHR", prefix + "'" + text + "'")); prefix = ""
            elif w == WORD_HEADER_BEGIN:
                text, i = _content_back(ws, i + 1, WORD_HEADER_END); toks.append(("HEADER", "<" + text + ">"))
            elif w in HEADER_WORD_TO_NAME:
                toks.append(("HEADER", HEADER_WORD_TO_NAME[w])); i += 1
            elif w == WORD_AAVESHA:
                toks.append(("ID", INCLUDE_DIRECTIVE)); i += 1
            elif w == WORD_MACRO_PAREN:
                toks.append(("GLUE", "(")); i += 1
            elif w == WORD_SPLICE:
                toks.append(("SPLICE", "\\")); i += 1
            elif w in WORD_TO_TOKEN:
                toks.append(("OP", WORD_TO_TOKEN[w])); i += 1
            else:
                toks.append(("ID", word_to_name(w))); i += 1
        lines.append(toks)
    return lines


def tokens_to_source(lines) -> str:
    out, depth = [], 0
    for toks in lines:
        if not toks:
            out.append(""); continue
        first = toks[0][1]
        shown = max(0, depth - 1) if first == "}" else depth
        s = ""
        for idx, (kind, text) in enumerate(toks):
            if idx == 0:
                s = text
            elif kind == "GLUE" or (idx == 1 and first == "#" and toks[0][0] == "OP"):
                s += text
            elif kind == "SPLICE":
                s += " \\"
            else:
                s += " " + text
        out.append(("" if first == "#" else "    " * shown) + s)
        depth = max(0, depth + sum(1 for k, t in toks if k == "OP" and t == "{") - sum(1 for k, t in toks if k == "OP" and t == "}"))
    return "\n".join(out) + "\n"


def sutram_to_source(sutram: str) -> str:
    return tokens_to_source([[(k, t) for k, t in line] for line in sutram_to_tokens(sutram)])
