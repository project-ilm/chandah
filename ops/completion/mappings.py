

# ===== chandah completion of sutram v11: a short word for every token, in any language Hindawi supports =====
# Everything above this line is v11 as given; below, only additions (docs/COMPLETION.md).

# Hindawi 2026.10's Sanskrit keywords (lang/hindawi/languages/sanskrit/c2h.uhin and cpp2h.uhin) that begin a
# declaration, and those after which * and & are unary. Other languages' come from chandah's language data, retrieved
# from the same tables; these are the defaults.
DECLARATION_STARTERS = {"पूर्णाङ्क", "वर्ण", "शून्य", "भिन्न", "द्विगुण", "दीर्घ", "ह्रस्व", "अचिह्नित", "चिह्नित", "संरचना",
                        "सङ्घ", "गणना", "ध्रुव", "स्थिर", "बाह्य", "प्रकारनिर्देश", "पञ्जिका", "चञ्चल", "स्वचालित",
                        "अन्तःस्थ", "तार्किक", "वर्ग", "प्रतिरूपम्", "प्रकारनाम"}
OPERAND_BREAKERS = DECLARATION_STARTERS | {"प्रत्यागम", "परिमाण", "पक्ष", "गच्छ", "अन्यथा", "कुरु", "यदि", "यावत्", "प्रति",
                                           "विकल्प", "क्षिप", "नूतन", "विलोपय", "स्वभाव"}
INCLUDE_DIRECTIVE = "अन्तर्भाव"
DEFINE_DIRECTIVES = {"परिभाषय", "define"}

# The chosen words, shortened; च, न and वा stay as they were. v11's parse-tree path reads the same words.
OP_TO_SUTRAM.update({"=": "स्था", "+=": "योगस्था", "-=": "ऊनस्था", "*=": "गुणस्था", "/=": "भागस्था", "%=": "शेषस्था",
                     "==": "सम", "!=": "असम", "<": "अल्प", ">": "अधिक", "<=": "अल्पसम", ">=": "अधिकसम",
                     "+": "योग", "-": "ऊन", "*_bin": "गुण", "/": "भाग", "%": "शेष", "!": "न", "&&": "च", "||": "वा",
                     "++": "वर्ध", "--": "क्षय", "&_addr": "पता", "*_deref": "वस्तु", "->": "द्वारा", ".": "मध्ये",
                     "::": "क्षेत्र"})
SUTRAM_TO_OP.clear()
SUTRAM_TO_OP.update({w: t for t, w in OP_TO_SUTRAM.items()})
TOKEN_WORDS = dict(OP_TO_SUTRAM)
TOKEN_WORDS.update({
    "{": WORD_ANU, "}": WORD_PURNA, "(": "समूह", ")": "इति", "[": "सूच", "]": "अवधि", ";": "दण्ड", ",": "यति",
    ":": "विसर्ग", "?": "किम्", "#": "पूर्व", "##": "सन्धि", "...": "आदि", "~": "विलोम", "^": "भेद", "|": "अथवा",
    "&_bin": "तथा", "<<": "वाम", ">>": "दक्ष", "&=": "तथास्था", "|=": "अथवास्था", "^=": "भेदस्था", "<<=": "वामस्था",
    ">>=": "दक्षस्था", ".*": "मध्येवस्तु", "->*": "द्वारावस्तु",
})
WORD_TO_TOKEN = {w: (t.split("_")[0] if t in ("*_bin", "*_deref", "&_addr", "&_bin") else t) for t, w in TOKEN_WORDS.items()}
assert len(WORD_TO_TOKEN) == len(TOKEN_WORDS), "two tokens share a word"

# markers of the complete base layer
WORD_EMPTY_LINE = "रिक्त"            # a line with no tokens, so line numbers survive
WORD_NUMBER = "अङ्क"                 # a number follows, in katapayadi or in Devanagari digits
WORD_NUMBER_FORM = "अङ्कादि"          # a number with a point, a base, an exponent or a suffix begins
WORD_NUMBER_FORM_END = "अङ्कान्त"
WORD_NATIVE_DIGITS = "स्वाङ्क"        # digits written in the language's own script follow, as written
WORD_STRING_BEGIN, WORD_STRING_END = "वाक्", "वागन्त"
WORD_CHAR_BEGIN, WORD_CHAR_END = "अक्षर", "अक्षरान्त"
WORD_LITERAL_PREFIX = "उपसर्ग"        # L, u, U or u8 before a string or character
WORD_HEADER_BEGIN, WORD_HEADER_END = "शीर्ष", "शीर्षान्त"
WORD_MACRO_PAREN = "प्राचल"          # the ( of a function-like macro, written against its name
WORD_SPLICE = "अनु"                  # a backslash joining a line to the next
WORD_NAME = "नाम"                    # the next word is a name, though it reads like one of these words
WORD_LITERALLY = "यथा"               # inside a string: the next word is text, as it is
WORD_CODEPOINT = "सङ्केत"             # inside a string: a character with no word of its own, by its number
LINE_MARKER_WORD = "पङ्क्त्यन्त"

NUMBER_CHAR_WORDS = {".": "बिन्दु", "+": "योग", "-": "ऊन", "_": "योजक", "'": "लोप"}
LITERAL_WORDS = {" ": "अन्तर", ".": "बिन्दु", ",": "यति", ":": "विसर्ग", ";": "दण्ड", "?": "किम्", "!": "विस्मय",
                 "-": "ऊन", "+": "योग", "*": "गुण", "/": "भाग", "=": "स्था", "<": "अल्प", ">": "अधिक", "%": "शत",
                 "&": "तथा", "|": "अथवा", "^": "भेद", "~": "विलोम", "(": "समूह", ")": "इति", "[": "सूच", "]": "अवधि",
                 "{": "अणु", "}": "पूर्ण", "#": "पूर्व", "\"": "उद्धृत", "'": "लोप", "\\": "तिर्यक्", "_": "योजक",
                 "$": "मुद्रा", "@": "विशेष", "`": "वक्र", "\t": "स्तम्भ"}
LITERAL_SEQUENCES = [("\\n", "नव"), ("%d", "पूर्णाङ्क"), ("%s", "पाठ")]
WORD_TO_LITERAL = {w: c for c, w in LITERAL_WORDS.items()}
WORD_TO_LITERAL.update({w: s for s, w in LITERAL_SEQUENCES})
assert len(WORD_TO_LITERAL) == len(LITERAL_WORDS) + len(LITERAL_SEQUENCES), "two characters share a word"
HEADER_WORD_TO_NAME = {words[0]: name for name, words in HEADER_MAP.items() if len(words) == 1}

CODE_RESERVED = (set(TOKEN_WORDS.values()) | set(HEADER_WORD_TO_NAME) |
                 {WORD_PARIBHASHIT, WORD_AAVESHA, WORD_EMPTY_LINE, WORD_NUMBER, WORD_NUMBER_FORM, WORD_NUMBER_FORM_END,
                  WORD_NATIVE_DIGITS, WORD_STRING_BEGIN, WORD_STRING_END, WORD_CHAR_BEGIN, WORD_CHAR_END,
                  WORD_LITERAL_PREFIX, WORD_HEADER_BEGIN, WORD_HEADER_END, WORD_MACRO_PAREN, WORD_SPLICE, WORD_NAME,
                  LINE_MARKER_WORD})
LITERAL_RESERVED = (set(WORD_TO_LITERAL) | {WORD_NUMBER, WORD_CODEPOINT, WORD_LITERALLY, WORD_STRING_END,
                                            WORD_CHAR_END, WORD_HEADER_END, LINE_MARKER_WORD})
_MARKERS = CODE_RESERVED - set(TOKEN_WORDS.values())
assert len(_MARKERS) == len(CODE_RESERVED) - len(set(TOKEN_WORDS.values())), "a marker is also a token's word"
STRUCT_WORDS = set(STRUCT_WORDS) | CODE_RESERVED | LITERAL_RESERVED | set(NUMBER_CHAR_WORDS.values())

_JOIN, _AVAGRAHA = "योजक", "ऽ"


def name_to_word(name: str) -> str:
    """'_' becomes योजक, as in v11; a योजक already in the name gains one avagraha, so every name comes back."""
    out, i = [], 0
    while i < len(name):
        if name[i] == "_":
            out.append(_JOIN); i += 1; continue
        if name.startswith(_JOIN, i):
            j = i + len(_JOIN)
            while j < len(name) and name[j] == _AVAGRAHA:
                j += 1
            out.append(name[i:j] + _AVAGRAHA); i = j; continue
        out.append(name[i]); i += 1
    return "".join(out)


def word_to_name(word: str) -> str:
    out, i = [], 0
    while i < len(word):
        if word.startswith(_JOIN, i):
            j = i + len(_JOIN)
            while j < len(word) and word[j] == _AVAGRAHA:
                j += 1
            k = j - i - len(_JOIN)
            out.append("_" if k == 0 else _JOIN + _AVAGRAHA * (k - 1)); i = j; continue
        out.append(word[i]); i += 1
    return "".join(out)
