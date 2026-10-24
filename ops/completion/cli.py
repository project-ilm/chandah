

# ===== chandah completion of sutram v11 (23 October 2026): the convenience wrappers carry the whole program =====
def c_to_sutram(src, numeral_mode='katapayadi', samasa_mode=None, apply_sandhi=True):
    from .forward import source_to_sutram
    from .sandhi_samasa import sutram_to_samasta
    base = source_to_sutram(src, numeral_mode=numeral_mode)
    return sutram_to_samasta(base, mode=samasa_mode, apply_sandhi=apply_sandhi) if samasa_mode else base


def sutram_to_c(sutram_text):
    from .reverse import sutram_to_source
    return sutram_to_source(sutram_text)
