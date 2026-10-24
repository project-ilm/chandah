# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. sutram v11, kept as given apart from these two
# lines, the corrections in docs/CORRECTIONS.md and the completion below its marker (docs/COMPLETION.md).
from .parser import parse_source
from .forward import program_to_sutram
from .reverse import parse_sutram
from .chhandas import format_anushtubh, format_anushtubh_bijective, parse_chhandas_bijective
from .sandhi_samasa import sutram_to_samasta, samasta_to_sutram

def c_to_sutram(src: str, with_chhandas=False, chhandas_bijective=False, chhandas_type='anushtubh', numeral_mode='devanagari', samasa_mode=None, apply_sandhi=False):
    preprocs, funcs = parse_source(src)
    sutram = program_to_sutram(preprocs, funcs, numeral_mode=numeral_mode)
    if samasa_mode:
        return sutram_to_samasta(sutram, mode=samasa_mode, apply_sandhi=apply_sandhi)
    if chhandas_bijective:
        from .chhandas import format_chhandas_bijective
        return format_chhandas_bijective(sutram, chhandas_type=chhandas_type)
    if with_chhandas:
        return format_anushtubh(sutram)
    return sutram

def sutram_to_c(sutram: str):
    return parse_sutram(sutram)

def chhandas_to_c(chhandas_text: str, bijective=False):
    from .chhandas import parse_chhandas_bijective
    if bijective:
        sutram = parse_chhandas_bijective(chhandas_text)
    else:
        # non-bijective: words order preserved, lines lost -> best effort rejoin
        sutram = " ".join(chhandas_text.replace("\n"," ").split())
        # fallback: try to parse as single stream? For now return words
    return parse_sutram(sutram)

def samasta_to_c(samasta_text: str, mode='line', known_identifiers=None):
    sutram = samasta_to_sutram(samasta_text, mode=mode, known_identifiers=known_identifiers)
    return parse_sutram(sutram)


# ===== chandah completion of sutram v11 : the convenience wrappers carry the whole program =====
def c_to_sutram(src, numeral_mode='katapayadi', samasa_mode=None, apply_sandhi=True):
    from .forward import source_to_sutram
    from .sandhi_samasa import sutram_to_samasta
    base = source_to_sutram(src, numeral_mode=numeral_mode)
    return sutram_to_samasta(base, mode=samasa_mode, apply_sandhi=apply_sandhi) if samasa_mode else base


def sutram_to_c(sutram_text):
    from .reverse import sutram_to_source
    return sutram_to_source(sutram_text)
