# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these two lines and the corrections recorded in docs/CORRECTIONS.md.
# Sandhi and Samasa layer — v4 bijective
# v1/v2 intact. Samasa + bijective sandhi.
LINE_MARKER = "पङ्क्त्यन्त"

def _sandhi_join_two(w1: str, w2: str) -> str:
    # Restricted bijective sandhi: visarga + sibilant
    if w1.endswith("ः") and w2.startswith("स"):
        return w1[:-1] + "स्स" + w2[1:]
    if w1.endswith("ः") and w2.startswith("श"):
        return w1[:-1] + "श्श" + w2[1:]
    if w1.endswith("ः") and w2.startswith("ष"):
        return w1[:-1] + "ष्ष" + w2[1:]
    return w1 + w2

def _unsandhi(compound: str) -> str:
    """Bijective inverse. स्स/श्श/ष्ष never occur naturally in vocab, safe to restore."""
    compound = compound.replace("श्श", "ःश")
    compound = compound.replace("ष्ष", "ःष")
    compound = compound.replace("स्स", "ःस")
    return compound

def _join_words(words, apply_sandhi=False):
    if not words:
        return ""
    out = words[0]
    for w in words[1:]:
        out = _sandhi_join_two(out, w) if apply_sandhi else out + w
    return out

def sutram_to_samasta(sutram_text: str, mode='line', apply_sandhi=False) -> str:
    lines = [l.strip() for l in sutram_text.strip().split("\n")]
    if mode == 'line':
        out_lines = []
        for l in lines:
            if not l:
                out_lines.append(""); continue
            out_lines.append(_join_words(l.split(), apply_sandhi=apply_sandhi))
        return "\n".join(out_lines)
    elif mode == 'full':
        all_words = []
        for l in lines:
            if not l: continue
            all_words.extend(l.split())
            all_words.append(LINE_MARKER)
        if all_words and all_words[-1]==LINE_MARKER:
            all_words=all_words[:-1]
        return _join_words(all_words, apply_sandhi=apply_sandhi)
    else:
        raise ValueError("mode must be 'line' or 'full'")

def _build_vocab():
    from .mappings import TYPES, KEYWORDS, STRUCT_WORDS, OPERATOR_WORDS
    vocab=set()
    vocab.update(TYPES); vocab.update(KEYWORDS); vocab.update(STRUCT_WORDS); vocab.update(OPERATOR_WORDS)
    vocab.update(["मानकप्रवाह","पूर्वनिर्देश","आवेशन","संख्याङ्क",LINE_MARKER])
    vocab.update(["प्रारूपपूर्णाङ्क","नूतनपङ्क्ति"])
    return vocab

def samasta_to_sutram(samasta_text: str, mode='line', known_identifiers=None) -> str:
    vocab=_build_vocab()
    if known_identifiers:
        vocab.update(known_identifiers)
    def _is_dep(ch: str) -> bool:
        o=ord(ch); return 0x093E <= o <= 0x094C
    sorted_vocab=sorted(vocab, key=len, reverse=True)
    def split_one(compound: str):
        compound=_unsandhi(compound)  # bijective sandhi reverse first
        words=[]; i=0; n=len(compound)
        while i<n:
            best=None; bl=0
            for v in sorted_vocab:
                if not compound.startswith(v,i): continue
                if len(v)==1 and i+1<n and _is_dep(compound[i+1]): continue
                if len(v)>bl: best=v; bl=len(v)
            if best:
                words.append(best); i+=bl; continue
            # fallback: take until next vocab
            nxt=n
            for v in vocab:
                pos=compound.find(v,i+1)
                if pos!=-1 and pos<nxt: nxt=pos
            words.append(compound[i:nxt]); i=nxt
        return words
    if mode=='line':
        out=[]
        for line in samasta_text.strip().split("\n"):
            if not line.strip(): out.append(""); continue
            out.append(" ".join(split_one(line.strip())))
        return "\n".join(out)
    else:
        comp="".join(samasta_text.strip().split())
        words=split_one(comp)
        lines=[]; cur=[]
        for w in words:
            if w==LINE_MARKER: lines.append(" ".join(cur)); cur=[]
            else: cur.append(w)
        if cur: lines.append(" ".join(cur))
        return "\n".join(lines)
