# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these lines, the corrections in docs/CORRECTIONS.md and the completion below its marker.
# Mappings for C-like (Sanskrit keywords) <-> Sutram (words only)
# No symbols in sutram output. All operators become single words.

OP_TO_SUTRAM = {
    "=": "स्थापय",
    "+=": "योजयस्थापय",
    "-=": "वियोजयस्थापय",
    "*=": "गुणयस्थापय",
    "/=": "विभजस्थापय",
    "%=": "शेषस्थापय",
    "==": "समम्",
    "!=": "नसमम्",
    "<": "अल्पतरम्",
    ">": "अधिकतरम्",
    "<=": "अल्पतरंवासमम्",
    ">=": "अधिकतरंवासमम्",
    "+": "योजय",
    "-": "वियोजय",
    "*_bin": "गुणय",
    "/": "विभज",
    "%": "शेषम्",
    "!": "न",
    "&&": "च",
    "||": "वा",
    "++": "वर्धय",
    "--": "क्षपय",
    "&_addr": "पता",
    "*_deref": "अन्तर्वस्तु",
    "->": "मध्ये",
    ".": "मध्ये",
    "::": "क्षेत्र",
}

SUTRAM_TO_OP = {v:k for k,v in OP_TO_SUTRAM.items()}

WORD_PARIBHASHIT = "परिभाषित"
WORD_ANU = "अणु"
WORD_PURNA = "पूर्ण"
WORD_SUCHAK = "सूचक"
WORD_NIRDESHAK = "निर्देशक"
WORD_AKAR = "आकार"
WORD_AKARHEEN = "आकारहीन"
WORD_UDDHARAN_ARAMBHA = "उद्धरणारम्भ"
WORD_UDDHARAN_ANTA = "उद्धरणान्त"
WORD_PURVANIRDESH = "पूर्वनिर्देश"
WORD_AAVESHA = "आवेशन"
WORD_SAMUHARAMBHA = "समूहारम्भ"
WORD_SAMUHANTA = "समूहान्त"

HEADER_MAP = {
    "<stdio.h>": ["मानकप्रवाह"],
}
HEADER_REVERSE = {tuple(v):k for k,v in HEADER_MAP.items()}

FORMAT_MAP = {
    "%d": "प्रारूपपूर्णाङ्क",
    "%s": "प्रारूपपाठ",
    "\\n": "नूतनपङ्क्ति",
}
FORMAT_REVERSE = {v:k for k,v in FORMAT_MAP.items()}

TYPES = {"पूर्णाङ्क", "शून्य"}
KEYWORDS = {"यावत्", "यदि", "अन्यथा", "प्रत्यागम"}
STRUCT_WORDS = {
    WORD_PARIBHASHIT, WORD_ANU, WORD_PURNA, WORD_SUCHAK,
    WORD_NIRDESHAK, WORD_AKAR, WORD_AKARHEEN,
    WORD_UDDHARAN_ARAMBHA, WORD_UDDHARAN_ANTA,
    WORD_PURVANIRDESH, WORD_AAVESHA,
    WORD_SAMUHARAMBHA, WORD_SAMUHANTA,
}
OPERATOR_WORDS = set(OP_TO_SUTRAM.values())
RESERVED = TYPES | KEYWORDS | STRUCT_WORDS | OPERATOR_WORDS | {"मानकप्रवाह"}

def ident_to_sutram(ident: str) -> str:
    return ident.replace("_", "योजक")

def sutram_to_ident(s: str) -> str:
    return s.replace("योजक", "_")


# ===== chandah completion of sutram v11 (23 October 2026): a word for every token of Sanskrit C and C++ =====
# Recorded in docs/COMPLETION.md. Everything above this line is v11 as given; below, only additions.

# Hindawi 2026.10's canonical Sanskrit keywords (lang/hindawi/languages/sanskrit/c2h.uhin and cpp2h.uhin), retrieved
# from its tables: those that begin a declaration, and those after which * and & are unary.
DECLARATION_STARTERS = {"पूर्णाङ्क", "वर्ण", "शून्य", "भिन्न", "द्विगुण", "दीर्घ", "ह्रस्व", "अचिह्नित", "चिह्नित", "संरचना",
                        "सङ्घ", "गणना", "ध्रुव", "स्थिर", "बाह्य", "प्रकारनिर्देश", "पञ्जिका", "चञ्चल", "स्वचालित",
                        "अन्तःस्थ", "तार्किक", "वर्ग", "प्रतिरूपम्", "प्रकारनाम"}
OPERAND_BREAKERS = DECLARATION_STARTERS | {"प्रत्यागम", "परिमाण", "पक्ष", "गच्छ", "अन्यथा", "कुरु", "यदि", "यावत्", "प्रति",
                                           "विकल्प", "क्षिप", "नूतन", "विलोपय", "स्वभाव"}
INCLUDE_DIRECTIVE = "अन्तर्भाव"
DEFINE_DIRECTIVES = {"परिभाषय", "define"}

# '.' keeps मध्ये; v11 gave '->' the same word, and a word must name one token, so '->' gets its own
OP_TO_SUTRAM["->"] = "निर्देशमध्ये"
TOKEN_WORDS = dict(OP_TO_SUTRAM)
TOKEN_WORDS.update({
    "{": WORD_ANU, "}": WORD_PURNA, "(": WORD_SAMUHARAMBHA, ")": WORD_SAMUHANTA, "[": WORD_SUCHAK, "]": "सूचकान्त",
    ";": "विराम", ",": "अल्पविराम", ":": "उपविराम", "?": "प्रश्नचिह्न", "#": WORD_PURVANIRDESH, "...": "इत्यादि",
    "~": "पूरक", "^": "अनन्यवा", "|": "अंशवा", "&_bin": "अंशच", "<<": "वामसर्पय", ">>": "दक्षिणसर्पय",
    "&=": "अंशचस्थापय", "|=": "अंशवास्थापय", "^=": "अनन्यवास्थापय", "<<=": "वामसर्पयस्थापय", ">>=": "दक्षिणसर्पयस्थापय",
    ".*": "मध्येअन्तर्वस्तु", "->*": "निर्देशमध्येअन्तर्वस्तु",
})
WORD_TO_TOKEN = {w: (t.split("_")[0] if t in ("*_bin", "*_deref", "&_addr", "&_bin") else t) for t, w in TOKEN_WORDS.items()}
assert len(WORD_TO_TOKEN) == len(TOKEN_WORDS), "two tokens share a word"

# markers of the complete base layer
WORD_EMPTY_LINE = "रिक्तपङ्क्ति"        # a line with no tokens, so line numbers survive
WORD_NUMBER = "संख्याङ्क"               # v11's: a number follows
WORD_NUMBER_FORM = "संख्यारूप"          # a number with a point, a base, an exponent or a suffix begins
WORD_NUMBER_FORM_END = "संख्यारूपान्त"
WORD_DEVA_DIGITS = "देवाङ्क"            # Devanagari digits written as such in the source follow
WORD_CHAR_BEGIN, WORD_CHAR_END = "वर्णारम्भ", "वर्णान्त"
WORD_LITERAL_PREFIX = "उद्धरणोपसर्ग"     # L, u, U or u8 before a string or character
WORD_HEADER_BEGIN, WORD_HEADER_END = "शीर्षकारम्भ", "शीर्षकान्त"
WORD_MACRO_PAREN = "प्राचलारम्भ"        # the ( of a function-like macro, written against its name
WORD_SPLICE = "पङ्क्तिसन्धि"           # a backslash joining a line to the next
WORD_NAME = "नाम"                      # the next word is a name, though it reads like one of these words
WORD_LITERALLY = "शब्दशः"              # inside a string: the next word is text, though it reads like one of these words
WORD_CODEPOINT = "वर्णसङ्केत"           # inside a string: a character with no word of its own, by its number

NUMBER_CHAR_WORDS = {".": "दशमलव", "+": "योजय", "-": "वियोजय", "_": "योजक", "'": "एकोद्धरणचिह्न"}
LITERAL_WORDS = {" ": "अवकाश", ".": "बिन्दु", ",": "अल्पविराम", ":": "उपविराम", ";": "विराम", "?": "प्रश्नचिह्न",
                 "!": "विस्मयचिह्न", "-": "वियोजय", "+": "योजय", "*": "गुणय", "/": "विभज", "=": "स्थापय",
                 "<": "अल्पतरम्", ">": "अधिकतरम्", "%": "प्रतिशत", "&": "अंशच", "|": "अंशवा", "^": "अनन्यवा", "~": "पूरक",
                 "(": "समूहारम्भ", ")": "समूहान्त", "[": "सूचक", "]": "सूचकान्त", "{": "अणु", "}": "पूर्ण",
                 "#": "पूर्वनिर्देश", "\"": "उद्धरणचिह्न", "'": "एकोद्धरणचिह्न", "\\": "पलायनचिह्न", "_": "योजक",
                 "$": "मुद्राचिह्न", "@": "विशेषचिह्न", "`": "प्रत्युद्धरणचिह्न", "\t": "स्तम्भान्तर"}
LITERAL_SEQUENCES = [("\\n", FORMAT_MAP["\\n"]), ("%d", FORMAT_MAP["%d"]), ("%s", FORMAT_MAP["%s"])]
WORD_TO_LITERAL = {w: c for c, w in LITERAL_WORDS.items()}
WORD_TO_LITERAL.update({w: s for s, w in LITERAL_SEQUENCES})
assert len({w for _, w in LITERAL_SEQUENCES} | set(LITERAL_WORDS.values())) == len(LITERAL_WORDS) + len(LITERAL_SEQUENCES)
HEADER_WORD_TO_NAME = {words[0]: name for name, words in HEADER_MAP.items() if len(words) == 1}
LINE_MARKER_WORD = "पङ्क्त्यन्त"

CODE_RESERVED = (set(TOKEN_WORDS.values()) | set(HEADER_WORD_TO_NAME) |
                 {WORD_PARIBHASHIT, WORD_AAVESHA, WORD_UDDHARAN_ARAMBHA, WORD_UDDHARAN_ANTA, WORD_EMPTY_LINE, WORD_NUMBER,
                  WORD_NUMBER_FORM, WORD_NUMBER_FORM_END, WORD_DEVA_DIGITS, WORD_CHAR_BEGIN, WORD_CHAR_END,
                  WORD_LITERAL_PREFIX, WORD_HEADER_BEGIN, WORD_HEADER_END, WORD_MACRO_PAREN, WORD_SPLICE, WORD_NAME,
                  LINE_MARKER_WORD})
LITERAL_RESERVED = (set(WORD_TO_LITERAL) | {WORD_NUMBER, WORD_CODEPOINT, WORD_LITERALLY, WORD_UDDHARAN_ANTA,
                                            WORD_CHAR_END, WORD_HEADER_END, LINE_MARKER_WORD})
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
