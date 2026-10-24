

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
