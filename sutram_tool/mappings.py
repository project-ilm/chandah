# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these two lines and the corrections recorded in docs/CORRECTIONS.md.
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
