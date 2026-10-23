#!/usr/bin/env python3
"""clean_invisible: remove invisible characters from a document before it is read, and say exactly what was removed.

Removed: zero-width spaces and joiners outside the scripts that use them, byte-order marks, soft hyphens, invisible
operators, bidirectional embeddings, overrides and isolates (the Trojan Source characters), deprecated format characters,
tag characters, interlinear annotation marks, Hangul fillers, the Mongolian vowel separator, and control characters other
than tab and newline. Normalised: unusual spaces to a plain space, line and paragraph separators to a newline.
Kept, and counted: the zero-width non-joiner and joiner where both neighbours are letters of a script whose spelling uses
them (Arabic script, the Indic scripts, Sinhala), and the joiner inside emoji sequences.
  clean_invisible.py <file> [--out cleaned] [--report report.json]       (with no --out, prints the cleaned text)
© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. MIT licence."""
import json, sys, unicodedata
from collections import Counter

REMOVE = {0x200B, 0x2060, 0xFEFF, 0x00AD, 0x180E, 0x061C, 0x200E, 0x200F, 0x115F, 0x1160, 0x3164, 0xFFA0, 0x034F}
REMOVE |= set(range(0x2061, 0x2065)) | set(range(0x202A, 0x202F)) | set(range(0x2066, 0x2070)) | set(range(0xFFF9, 0xFFFC))
REMOVE |= set(range(0xE0000, 0xE0080))
SPACES = {0x00A0, 0x202F, 0x205F, 0x3000} | set(range(0x2000, 0x200B))
JOINER_SCRIPTS = [(0x0600, 0x06FF), (0x0750, 0x077F), (0x08A0, 0x08FF), (0xFB50, 0xFDFF), (0xFE70, 0xFEFF), (0x0900, 0x0DFF)]


def _script_letter(ch):
    o = ord(ch)
    return any(a <= o <= b for a, b in JOINER_SCRIPTS) and unicodedata.category(ch)[0] in "LM"


def _emoji(ch):
    return ord(ch) >= 0x1F000 or 0x2600 <= ord(ch) <= 0x27BF


def clean(text):
    out, removed, kept, normalised = [], Counter(), Counter(), Counter()
    where = {}
    line, col = 1, 0
    for i, ch in enumerate(text):
        o = ord(ch)
        col += 1
        if ch == "\n":
            line, col = line + 1, 0
        prev = text[i - 1] if i else ""
        nxt = text[i + 1] if i + 1 < len(text) else ""
        if o in (0x200C, 0x200D):
            if (prev and nxt and _script_letter(prev) and _script_letter(nxt)) or (o == 0x200D and prev and nxt and _emoji(prev) and _emoji(nxt)):
                kept[f"U+{o:04X}"] += 1; out.append(ch); continue
            removed[f"U+{o:04X}"] += 1; where.setdefault(f"U+{o:04X}", f"{line}:{col}"); continue
        if o in REMOVE or (unicodedata.category(ch) == "Cc" and ch not in "\t\n\r"):
            removed[f"U+{o:04X}"] += 1; where.setdefault(f"U+{o:04X}", f"{line}:{col}"); continue
        if o in SPACES:
            normalised[f"U+{o:04X} to space"] += 1; out.append(" "); continue
        if o in (0x2028, 0x2029):
            normalised[f"U+{o:04X} to newline"] += 1; out.append("\n"); continue
        out.append(ch)
    names = lambda c: {k: {"count": v, "name": unicodedata.name(chr(int(k[2:6], 16)), "?") if len(k) <= 6 else k, **({"first": where[k]} if k in where else {})}
                       for k, v in c.items()}
    return "".join(out), {"removed": names(removed), "kept_orthographic": names(kept), "normalised": dict(normalised)}


if __name__ == "__main__":
    args = sys.argv[1:]
    if not args or args[0] in ("-h", "--help"):
        print(__doc__); sys.exit(0)
    src = args[0]; out = rep = None
    if "--out" in args: out = args[args.index("--out") + 1]
    if "--report" in args: rep = args[args.index("--report") + 1]
    raw = open(src, "rb").read()
    text = raw.decode("utf-8", errors="replace")
    cleaned, report = clean(text)
    report["file"] = src; report["bytes_before"] = len(raw); report["bytes_after"] = len(cleaned.encode("utf-8"))
    report["replacement_characters"] = text.count("\ufffd")
    if out:
        open(out, "w", encoding="utf-8").write(cleaned)
    else:
        sys.stdout.write(cleaned)
    print(json.dumps(report, ensure_ascii=False, indent=1), file=open(rep, "w", encoding="utf-8") if rep else sys.stderr)
