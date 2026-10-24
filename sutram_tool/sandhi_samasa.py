# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these lines, the corrections in docs/CORRECTIONS.md and the completion below its marker.
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


# ===== chandah completion of sutram v11 (23 October 2026): compounds that always come back =====
# A compound is formed only if the splitter brings back exactly the words it was made of; otherwise the run of words is
# closed and a new compound begins. The decoder splits each space-separated compound on its own. So every samasa comes
# back by construction, whatever the program. v11's join and its visarga sandhi are unchanged.
def _build_vocab():
    from .mappings import TYPES, KEYWORDS, STRUCT_WORDS, OPERATOR_WORDS
    vocab = set()
    vocab.update(TYPES); vocab.update(KEYWORDS); vocab.update(STRUCT_WORDS); vocab.update(OPERATOR_WORDS)
    vocab.update(["मानकप्रवाह", "पूर्वनिर्देश", "आवेशन", "संख्याङ्क", LINE_MARKER, "प्रारूपपूर्णाङ्क", "नूतनपङ्क्ति"])
    return vocab


def _splitter(known_identifiers=None, sandhi=True):
    vocab = _build_vocab() | set(known_identifiers or ())
    lengths = sorted({len(v) for v in vocab}, reverse=True)

    def _is_dep(ch):
        return 0x093E <= ord(ch) <= 0x094C

    def _match(text, i):
        n = len(text)
        for L in lengths:
            if L <= n - i and text[i:i + L] in vocab and not (L == 1 and i + 1 < n and _is_dep(text[i + 1])):
                return L
        return 0

    def split_one(chunk):
        if chunk in vocab:
            return [chunk]
        text = _unsandhi(chunk) if sandhi else chunk
        words, i, n = [], 0, len(text)
        while i < n:
            L = _match(text, i)
            if L:
                words.append(text[i:i + L]); i += L; continue
            j = i + 1
            while j < n and not _match(text, j):
                j += 1
            words.append(text[i:j]); i = j
        return words
    return split_one


def _compound_runs(words, split_one, apply_sandhi, cap=12):
    runs, cur = [], []
    for w in words:
        trial = cur + [w]
        if len(trial) <= cap and split_one(_join_words(trial, apply_sandhi)) == trial:
            cur = trial
            continue
        if cur:
            runs.append(cur)
        if split_one(_join_words([w], apply_sandhi)) != [w]:
            raise ValueError(f"the word {w!r} cannot be carried through samasa")
        cur = [w]
    if cur:
        runs.append(cur)
    return [_join_words(r, apply_sandhi) for r in runs]


def _identifiers_in(sutram_text):
    vocab = _build_vocab()
    return {w for line in sutram_text.splitlines() for w in line.split()
            if w not in vocab and not (w and "\u0966" <= w[0] <= "\u096F")}


def sutram_to_samasta(sutram_text: str, mode='line', apply_sandhi=False, known_identifiers=None) -> str:
    if mode not in ("line", "full"):
        raise ValueError("mode must be 'line' or 'full'")
    if known_identifiers is None:
        known_identifiers = _identifiers_in(sutram_text)
    split_one = _splitter(known_identifiers, apply_sandhi)
    lines = [l.split() for l in sutram_text.strip("\n").split("\n")]
    if mode == "line":
        return "\n".join(" ".join(_compound_runs(ws, split_one, apply_sandhi)) for ws in lines)
    words = []
    for ws in lines:
        words += ws + [LINE_MARKER]
    chunks = _compound_runs(words[:-1], split_one, apply_sandhi)
    return "\n".join(" ".join(chunks[k:k + 8]) for k in range(0, len(chunks), 8))


def samasta_to_sutram(samasta_text: str, mode='line', known_identifiers=None, apply_sandhi=True) -> str:
    split_one = _splitter(known_identifiers, apply_sandhi)
    if mode == "line":
        return "\n".join(" ".join(w for c in line.split() for w in split_one(c))
                         for line in samasta_text.strip("\n").split("\n"))
    lines, cur = [], []
    for w in (w for c in samasta_text.split() for w in split_one(c)):
        if w == LINE_MARKER:
            lines.append(" ".join(cur)); cur = []
        else:
            cur.append(w)
    lines.append(" ".join(cur))
    return "\n".join(lines)
