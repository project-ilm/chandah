# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these two lines and the corrections recorded in docs/CORRECTIONS.md.
import re

token_spec = [
    ("COMMENT", r"/\*.*?\*/|//[^\n]*"),  # C1: comments before operators, and line comments
    ("PREPROC", r"\#अन्तर्भाव"),
    ("STRING", r'"(?:\\.|[^"\\])*"'),
    ("NUMBER", r"\d+"),
    ("IDENT", r"[\u0900-\u097F_a-zA-Z][\u0900-\u097F_a-zA-Z0-9]*"),
    ("OP", r"==|!=|<=|>=|\+=|-=|\*=|/=|%=|&&|\|\||\+\+|--|->|::|[+\-*/%<>=!&|?:.,;(){}\[\]#]"),
    ("LTGT", r"[<>]"),
    ("SKIP", r"[ \t\r\n]+"),
]

tok_re = re.compile("|".join(f"(?P<{n}>{p})" for n,p in token_spec), re.DOTALL)

def lex(src: str):
    toks = []
    for m in tok_re.finditer(src):
        kind = m.lastgroup
        val = m.group()
        if kind in ("SKIP","COMMENT"):
            continue
        toks.append((kind,val))
    return toks
