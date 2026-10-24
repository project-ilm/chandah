

# ===== chandah completion of sutram v11 (23 October 2026): encode and decode carry the whole program =====
# The base layer is now source_to_sutram (every token of Sanskrit C or C++); decode returns compilable Sanskrit C.
# The structure and sandhi layers keep v11's order: structure first, sandhi after it, never before.
from .forward import source_to_sutram
from .reverse import sutram_to_source
from .sandhi_samasa import _splitter, _compound_runs


def encode(src: str, numeral_mode='devanagari', structure=None, apply_sandhi=False):
    if numeral_mode not in NUMERAL_CHOICES:
        raise ValueError(f"numeral_mode must be one of {NUMERAL_CHOICES}")
    if structure not in STRUCTURE_CHOICES:
        raise ValueError(f"structure must be one of {STRUCTURE_CHOICES}")
    base_sutram = source_to_sutram(src, numeral_mode=numeral_mode)
    known_ids = sorted(_collect_identifiers(base_sutram))
    encoded = base_sutram
    if structure is not None and structure.startswith("samasa"):
        encoded = sutram_to_samasta(base_sutram, mode="line" if structure == "samasa_line" else "full",
                                    apply_sandhi=apply_sandhi, known_identifiers=known_ids)
    elif structure is not None:
        encoded = format_chhandas_bijective(base_sutram, chhandas_type=structure.split("_", 1)[1])
        if apply_sandhi:
            split_one = _splitter(known_ids, True)
            out = []
            for line in encoded.split("\n"):
                ls = line.strip()
                out.append(line if not ls or ls == "पङ्क्त्यन्त" else " ".join(_compound_runs(ls.split(), split_one, True)))
            encoded = "\n".join(out)
    return encoded, {"numeral_mode": numeral_mode, "structure": structure, "apply_sandhi": bool(apply_sandhi),
                     "known_identifiers": known_ids, "base_sutram": base_sutram}


def decode(encoded_text: str, metadata: dict):
    structure, apply_sandhi = metadata["structure"], metadata["apply_sandhi"]
    known_ids = set(metadata.get("known_identifiers", []))
    if structure is None:
        intermediate = encoded_text
    elif structure.startswith("samasa"):
        intermediate = samasta_to_sutram(encoded_text, mode="line" if structure == "samasa_line" else "full",
                                         known_identifiers=known_ids, apply_sandhi=apply_sandhi)
    else:
        text = encoded_text
        if apply_sandhi:
            out = []
            for line in text.split("\n"):
                ls = line.strip()
                out.append(line if not ls or ls == "पङ्क्त्यन्त" else
                           samasta_to_sutram(ls, mode="line", known_identifiers=known_ids, apply_sandhi=True))
            text = "\n".join(out)
        intermediate = parse_chhandas_generic(text)
    return sutram_to_source(intermediate), intermediate
