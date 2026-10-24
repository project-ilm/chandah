# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these lines, the corrections in docs/CORRECTIONS.md and the completion below its marker.
import re
_vowel_pat = re.compile(r'[\u0904-\u0914\u093E-\u094C]')
CHHANDAS_LB = "पङ्क्त्यन्त"

def approx_syllables(word: str) -> int:
    if not word: return 0
    if word==CHHANDAS_LB: return 0  # marker does not count for meter
    c=len(_vowel_pat.findall(word))
    base=len(re.findall(r'[\u0900-\u097F]', word))
    if c==0: return max(1, base//3 if base>0 else 1)
    return max(1,c)

def format_anushtubh(sutram_text: str) -> str:
    # original non-bijective, keeps <LB> internal but discards in output
    words=[]
    for line in sutram_text.split("\n"):
        if not line.strip(): continue
        words.extend(line.split()); words.append("<LB>")
    padas=[]; cur=[]; syl=0
    for w in words:
        if w=="<LB>":
            if cur and syl>=6: padas.append(cur); cur=[]; syl=0
            continue
        s=approx_syllables(w)
        if syl+s>8 and cur: padas.append(cur); cur=[]; syl=0
        cur.append(w); syl+=s
        if syl>=8: padas.append(cur); cur=[]; syl=0
    if cur: padas.append(cur)
    out=[]
    for i,p in enumerate(padas):
        out.append(" ".join(p))
        if (i+1)%4==0: out.append("")
    return "\n".join(out).strip()

def format_anushtubh_bijective(sutram_text: str) -> str:
    """Bijective chhandas: original line breaks encoded as पङ्क्त्यन्त before meter.
    Your suggestion: apply line break markers in original input, then adjust into chandas.
    """
    # Step 1: inject markers
    words=[]
    for line in sutram_text.strip().split("\n"):
        if not line.strip(): continue
        words.extend(line.split())
        words.append(CHHANDAS_LB)
    if words and words[-1]==CHHANDAS_LB: words=words[:-1]
    # Step 2: format into 8-syllable padas, forcing break on marker but keeping marker
    padas=[]; cur=[]; syl=0
    for w in words:
        if w==CHHANDAS_LB:
            # flush current pada, then marker as its own break
            if cur: padas.append(cur); cur=[]; syl=0
            padas.append([CHHANDAS_LB])
            continue
        s=approx_syllables(w)
        if syl+s>8 and cur: padas.append(cur); cur=[]; syl=0
        cur.append(w); syl+=s
        if syl>=8: padas.append(cur); cur=[]; syl=0
    if cur: padas.append(cur)
    out=[]
    for i,p in enumerate(padas):
        out.append(" ".join(p))
        if (i+1)%4==0: out.append("")
    return "\n".join(out).strip()

def parse_chhandas_bijective(chhandas_text: str) -> str:
    """Reverse of bijective chhandas: recover original line breaks."""
    all_words=[]
    for line in chhandas_text.strip().split("\n"):
        if not line.strip(): continue
        all_words.extend(line.split())
    # Split by marker
    lines=[]; cur=[]
    for w in all_words:
        if w==CHHANDAS_LB:
            lines.append(" ".join(cur)); cur=[]
        else:
            cur.append(w)
    if cur: lines.append(" ".join(cur))
    return "\n".join(lines)


# Various chhandas types - generic syllable-based, bijective via पङ्क्त्यन्त
CHHANDAS_TYPES = {
    "anushtubh": {"syllables_per_pada": 8, "padas_per_shloka": 4, "desc": "8x4=32"},
    "gayatri": {"syllables_per_pada": 8, "padas_per_shloka": 3, "desc": "8x3=24"},
    "trishtubh": {"syllables_per_pada": 11, "padas_per_shloka": 4, "desc": "11x4=44"},
    "jagati": {"syllables_per_pada": 12, "padas_per_shloka": 4, "desc": "12x4=48"},
}

def format_chhandas_bijective(sutram_text: str, chhandas_type="anushtubh") -> str:
    """Bijective chhandas for various types. Markers first, then meter, then sandhi (caller does sandhi after)."""
    cfg=CHHANDAS_TYPES.get(chhandas_type, CHHANDAS_TYPES["anushtubh"])
    spp=cfg["syllables_per_pada"]; pps=cfg["padas_per_shloka"]
    words=[]
    for line in sutram_text.strip().split("\n"):
        if not line.strip(): continue
        words.extend(line.split()); words.append(CHHANDAS_LB)
    if words and words[-1]==CHHANDAS_LB: words=words[:-1]
    padas=[]; cur=[]; syl=0
    for w in words:
        if w==CHHANDAS_LB:
            if cur: padas.append(cur); cur=[]; syl=0
            padas.append([CHHANDAS_LB]); continue
        s=approx_syllables(w)
        if syl+s>spp and cur: padas.append(cur); cur=[]; syl=0
        cur.append(w); syl+=s
        if syl>=spp: padas.append(cur); cur=[]; syl=0
    if cur: padas.append(cur)
    out=[]
    for i,p in enumerate(padas):
        out.append(" ".join(p))
        if (i+1)%pps==0: out.append("")
    return "\n".join(out).strip()

def parse_chhandas_generic(chhandas_text: str) -> str:
    all_words=[]
    for line in chhandas_text.strip().split("\n"):
        if not line.strip(): continue
        all_words.extend(line.split())
    lines=[]; cur=[]
    for w in all_words:
        if w==CHHANDAS_LB: lines.append(" ".join(cur)); cur=[]
        else: cur.append(w)
    if cur: lines.append(" ".join(cur))
    return "\n".join(lines)
