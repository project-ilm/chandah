# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these two lines and the corrections recorded in docs/CORRECTIONS.md.

"""Entire system: multiple outputs, chhandas choices, encoder/decoder, compilable."""
from .parser import parse_source
from .forward import program_to_sutram
from .reverse import parse_sutram
from .chhandas import format_chhandas_bijective, parse_chhandas_generic, CHHANDAS_TYPES
from .sandhi_samasa import sutram_to_samasta, samasta_to_sutram, _build_vocab, _sandhi_join_two, _unsandhi

# Stage definitions for user
NUMERAL_CHOICES = ['devanagari', 'katapayadi']  # stage1: words+numbers, stage2: completely words
STRUCTURE_CHOICES = [None, 'samasa_line', 'samasa_full', 'chhandas_anushtubh', 'chhandas_gayatri', 'chhandas_trishtubh', 'chhandas_jagati']

def _collect_identifiers(sutram_text):
    vocab=_build_vocab()
    ids=set()
    for line in sutram_text.splitlines():
        for w in line.split():
            if w not in vocab and w!='पङ्क्त्यन्त':
                # keep words that look like identifiers (not purely digits)
                if not (w and w[0] in '०१२३४५६७८९'):
                    # exclude संख्याङ्क marker handled separately
                    ids.add(w)
    # also add katapayadi decoded? No, keep as is
    return ids

def encode(src: str, numeral_mode='devanagari', structure=None, apply_sandhi=False):
    """
    Encoder with multiple outputs.
    - numeral_mode: 'devanagari' (stage1 words+numbers) or 'katapayadi' (stage2 completely words)
    - structure: None, 'samasa_line', 'samasa_full', 'chhandas_anushtubh', etc.
    - apply_sandhi: False/True. If True, applied AFTER samasa or AFTER chhandas, never before.
    Returns (encoded_text, metadata)
    """
    if numeral_mode not in NUMERAL_CHOICES:
        raise ValueError(f"numeral_mode must be {NUMERAL_CHOICES}")
    if structure not in STRUCTURE_CHOICES:
        raise ValueError(f"structure must be {STRUCTURE_CHOICES}")
    # Stage 1/2: base sutram
    preprocs, funcs = parse_source(src)
    base_sutram = program_to_sutram(preprocs, funcs, numeral_mode=numeral_mode)
    known_ids = _collect_identifiers(base_sutram)

    encoded = base_sutram
    # Non-waterfall: choose branch
    if structure is None:
        # No samasa/chhandas, sandhi alone not meaningful, keep base
        pass
    elif structure.startswith('samasa'):
        mode = 'line' if structure=='samasa_line' else 'full'
        # Samasa before sandhi
        encoded = sutram_to_samasta(base_sutram, mode=mode, apply_sandhi=apply_sandhi)
    elif structure.startswith('chhandas'):
        ctype = structure.split('_',1)[1]  # anushtubh etc.
        # Chhandas first, then sandhi
        encoded = format_chhandas_bijective(base_sutram, chhandas_type=ctype)
        if apply_sandhi:
            # word-to-word sandhi per chhandas line (samasa-like join per pada)
            out_lines=[]
            for line in encoded.split("\n"):
                ls=line.strip()
                if not ls or ls=="पङ्क्त्यन्त":
                    out_lines.append(line); continue
                words=ls.split()
                acc=words[0]
                for w in words[1:]:
                    acc=_sandhi_join_two(acc,w)
                out_lines.append(acc)
            encoded = "\n".join(out_lines)
    metadata = {
        'numeral_mode': numeral_mode,
        'structure': structure,
        'apply_sandhi': apply_sandhi,
        'known_identifiers': list(known_ids),
        'base_sutram': base_sutram,
    }
    return encoded, metadata

def _unsandhi_chhandas_line(line: str):
    # Reverse per-line sandhi join: unsandhi then split via vocab
    # We reuse samasta_to_sutram split logic for one line
    # For simplicity, use samasta_to_sutram with mode='line' on single line
    tmp = samasta_to_sutram(line, mode='line', known_identifiers=set())
    # samasta_to_sutram already does _unsandhi internally
    return tmp

def decode(encoded_text: str, metadata: dict):
    """
    Decoder mirrors encoder in reverse order.
    """
    numeral_mode = metadata['numeral_mode']
    structure = metadata['structure']
    apply_sandhi = metadata['apply_sandhi']
    known_ids = set(metadata.get('known_identifiers', []))

    # Reverse order: sandhi -> structure -> numeral (numeral handled in parse_sutram)
    intermediate_sutram = None

    if structure is None:
        intermediate_sutram = encoded_text
    elif structure.startswith('samasa'):
        mode = 'line' if structure=='samasa_line' else 'full'
        # samasta_to_sutram already handles unsandhi bijectively
        intermediate_sutram = samasta_to_sutram(encoded_text, mode=mode, known_identifiers=known_ids)
    elif structure.startswith('chhandas'):
        # First reverse sandhi if applied
        tmp_text = encoded_text
        if apply_sandhi:
            # Per line: unsandhi then split
            # We need vocab-aware split; use samasta_to_sutram line split with known_ids
            out_lines=[]
            for line in tmp_text.split("\n"):
                if not line.strip() or line.strip()=="पङ्क्त्यन्त":
                    out_lines.append(line); continue
                # Use samasta_to_sutram to split this sandhied pada
                # It does _unsandhi + vocab split
                split = samasta_to_sutram(line, mode='line', known_identifiers=known_ids)
                out_lines.append(split)
            tmp_text = "\n".join(out_lines)
        # Then reverse chhandas
        intermediate_sutram = parse_chhandas_generic(tmp_text)

    # intermediate_sutram should equal base_sutram
    # Now convert to Sanskrit C source
    sanskrit_c = parse_sutram(intermediate_sutram)
    return sanskrit_c, intermediate_sutram

def ensure_compiles(sanskrit_c_src: str):
    """Compile and run Sanskrit C through Hindawi, which lowers it through Romenagri to the host compiler.
    Returns (host_c, output): the program the compiler receives (`hin host sanskrit`) and what it prints
    (`hin run sanskrit`). Raises RuntimeError when Hindawi is not here, or the program does not build and run.
    C2: the given body replaced a fixed list of words and returned a binary-search result computed in Python,
    whatever the program; nothing here simulates a build."""
    import os, shutil, subprocess, sys, tempfile
    hin = shutil.which("hin")
    home = os.environ.get("HINDAWI_HOME", "")
    if hin:
        cmd = [hin]
    elif home and os.path.exists(os.path.join(home, "bin", "hin")):
        cmd = [sys.executable, os.path.join(home, "bin", "hin")]
    else:
        raise RuntimeError("Hindawi is not here: run the notebook's Installation cell, or set HINDAWI_HOME to a Hindawi tree")
    with tempfile.TemporaryDirectory() as d:
        path = os.path.join(d, "program.c")
        with open(path, "w", encoding="utf-8") as f:
            f.write(sanskrit_c_src)
        host = subprocess.run(cmd + ["host", "sanskrit", path], capture_output=True, text=True, timeout=300)
        run = subprocess.run(cmd + ["run", "sanskrit", path], stdin=subprocess.DEVNULL, capture_output=True, text=True, timeout=300)
    if host.returncode or run.returncode:
        raise RuntimeError("Hindawi could not build and run it:\n" + (run.stderr or run.stdout or host.stderr).strip()[-2000:])
    return host.stdout, run.stdout
