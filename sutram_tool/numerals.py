# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. sutram v11, kept as given apart from these two
# lines, the corrections in docs/CORRECTIONS.md and the completion below its marker (docs/COMPLETION.md).
_AR = "०१२३४५६७८९"
_EN = "0123456789"
_EN2AR = str.maketrans(_EN, _AR)
_AR2EN = str.maketrans(_AR, _EN)

def to_devanagari_digits(s: str) -> str:
    return s.translate(_EN2AR)

def to_latin_digits(s: str) -> str:
    return s.translate(_AR2EN)

def is_devanagari_number(w: str) -> bool:
    return len(w)>0 and all(ch in _AR for ch in w)
