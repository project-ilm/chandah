

# ===== chandah completion of sutram v11 (23 October 2026): the base layer for the whole of Sanskrit C and C++ =====
# source_to_sutram(src) carries every token of every line as words: v11's words for what v11 already named, and a word
# for every other token. program_to_sutram above is unchanged and still serves the parse-tree path.
import re as _re
from .mappings import (TOKEN_WORDS, DECLARATION_STARTERS, OPERAND_BREAKERS, INCLUDE_DIRECTIVE, DEFINE_DIRECTIVES,
                       CODE_RESERVED, LITERAL_RESERVED, LITERAL_WORDS, LITERAL_SEQUENCES, NUMBER_CHAR_WORDS,
                       WORD_EMPTY_LINE, WORD_NUMBER, WORD_NUMBER_FORM, WORD_NUMBER_FORM_END, WORD_DEVA_DIGITS,
                       WORD_CHAR_BEGIN, WORD_CHAR_END, WORD_LITERAL_PREFIX, WORD_HEADER_BEGIN, WORD_HEADER_END,
                       WORD_MACRO_PAREN, WORD_SPLICE, WORD_NAME, WORD_LITERALLY, WORD_CODEPOINT, name_to_word,
                       word_to_name)

_DECL_AFTER = {";", "{", "}", "(", ",", ":"}


def _is_deva(c):
    return "\u0900" <= c <= "\u097F" or c in "\u200c\u200d"


def _digits(s, numeral_mode):
    return encode_katapayadi(s, reverse_order=True) if numeral_mode == "katapayadi" else to_devanagari_digits(s)


def _number_words(text, numeral_mode):
    if _re.fullmatch(r"[0-9]+", text):
        return ([WORD_NUMBER, _digits(text, "katapayadi")] if numeral_mode == "katapayadi" else [to_devanagari_digits(text)])
    out = [WORD_NUMBER_FORM]
    for m in _re.finditer(r"[0-9]+|[\u0966-\u096F]+|[A-Za-z]+|.", text):
        s = m.group()
        if s[0] in "0123456789":
            out.append(_digits(s, numeral_mode))
        elif "\u0966" <= s[0] <= "\u096F":
            out += [WORD_DEVA_DIGITS, s]
        elif s.isascii() and s.isalpha():
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
            if _is_deva(c):
                j = i
                while j < n and _is_deva(inner[j]):
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
    begin, end = (WORD_UDDHARAN_ARAMBHA, WORD_UDDHARAN_ANTA) if quote == '"' else (WORD_CHAR_BEGIN, WORD_CHAR_END)
    return out + [begin] + _content_words(inner, numeral_mode) + [end]


def _header_words(text, numeral_mode):
    if text in HEADER_MAP and len(HEADER_MAP[text]) == 1:
        return list(HEADER_MAP[text])
    return [WORD_HEADER_BEGIN] + _content_words(text[1:-1], numeral_mode) + [WORD_HEADER_END]


def _operand(prev):
    if prev is None:
        return False
    kind, text = prev
    return (kind in ("NUM", "STR", "CHR") or (kind == "ID" and text not in OPERAND_BREAKERS)
            or (kind == "OP" and text in (")", "]", "++", "--")))


def _name_words(text):
    word = name_to_word(text)
    if word_to_name(word) != text:
        raise ValueError(f"the name {text!r} cannot be carried as one word")
    return [WORD_NAME, word] if word in CODE_RESERVED or word == WORD_NAME else [word]


def source_to_sutram(src: str, numeral_mode: str = "devanagari") -> str:
    from .lexer import lex_program
    out = []
    for toks in lex_program(src):
        if not toks:
            out.append(WORD_EMPTY_LINE); continue
        words, prev = [], None
        pp = toks[0][1] == "#" and toks[0][0] == "OP"
        directive = toks[1][1] if pp and len(toks) > 1 and toks[1][0] == "ID" else None
        for idx, (kind, text, spaced) in enumerate(toks):
            if kind == "ID":
                if pp and idx == 1 and text == INCLUDE_DIRECTIVE:
                    words.append(WORD_AAVESHA)
                else:
                    if not pp and text in DECLARATION_STARTERS and (prev is None or (prev[0] == "OP" and prev[1] in _DECL_AFTER)):
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
            elif text == "(" and pp and directive in DEFINE_DIRECTIVES and idx == 3 and not spaced:
                words.append(WORD_MACRO_PAREN)
            elif text == "*":
                words.append(TOKEN_WORDS["*_bin" if _operand(prev) else "*_deref"])
            elif text == "&":
                words.append(TOKEN_WORDS["&_bin" if _operand(prev) else "&_addr"])
            else:
                words.append(TOKEN_WORDS[text])
            prev = (kind, text)
        out.append(" ".join(words))
    return "\n".join(out)
