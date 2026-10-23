# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these two lines and the corrections recorded in docs/CORRECTIONS.md.
# Katapayadi encoder v2 addon — pandit-readable numerals
# Keeps v1 (Devanagari digits) intact. This is optional mode.
# Classical mapping from HitXP / Kerala tradition:
# 1: क ट प य ; 2: ख ठ फ र ; 3: ग ड ब ल ; 4: घ ढ भ व ; 5: ङ ण म श
# 6: च त ष ; 7: छ थ स ; 8: ज द ह ; 9: झ ध ; 0: ञ न
# Vowels are ignored. Traditional order is vamato gatih (reverse).
# For code use we provide deterministic reversible simple mapping.

_SIMPLE_MAP = {
    '0': 'न',
    '1': 'क',
    '2': 'ख',
    '3': 'ग',
    '4': 'घ',
    '5': 'ङ',
    '6': 'च',
    '7': 'छ',
    '8': 'ज',
    '9': 'झ',
}

_REVERSE_MAP = {}
for d, cons in _SIMPLE_MAP.items():
    _REVERSE_MAP[cons] = d
# also accept full classical variants for decoding
_CLASSICAL_VARIANTS = {
    '1': ['क','ट','प','य'],
    '2': ['ख','ठ','फ','र'],
    '3': ['ग','ड','ब','ल'],
    '4': ['घ','ढ','भ','व'],
    '5': ['ङ','ण','म','श'],
    '6': ['च','त','ष'],
    '7': ['छ','थ','स'],
    '8': ['ज','द','ह'],
    '9': ['झ','ध'],
    '0': ['ञ','न'],
}
for d, lst in _CLASSICAL_VARIANTS.items():
    for c in lst:
        _REVERSE_MAP.setdefault(c, d)

def encode_katapayadi(num_str: str, reverse_order=True) -> str:
    """Encode latin digit string to katapayadi word.
    reverse_order=True follows ankananam vamato gatih (traditional)."""
    s = ''.join(ch for ch in num_str if ch.isdigit())
    if not s:
        return ""
    if reverse_order:
        s = s[::-1]
    # map each digit to consonant + 'अ' implicit; join
    # Add 'अ' vowel by just consonant (inherent a)
    return ''.join(_SIMPLE_MAP[d] for d in s)

def decode_katapayadi(word: str, reverse_order=True) -> str:
    """Decode katapayadi word to latin digit string. Ignores vowels and non-mapped."""
    digits = []
    for ch in word:
        if ch in _REVERSE_MAP:
            digits.append(_REVERSE_MAP[ch])
    # digits are in encoded order (reversed if traditional)
    if reverse_order:
        digits = digits[::-1]
    return ''.join(digits)

def is_katapayadi_word(w: str) -> bool:
    # heuristic: all consonants in map, no devanagari digits
    return len(w)>0 and all(ch in _REVERSE_MAP or ch in 'अआइईउऊएऐओऔंः' for ch in w)
