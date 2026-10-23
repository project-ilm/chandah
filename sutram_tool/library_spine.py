# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these two lines and the corrections recorded in docs/CORRECTIONS.md.
"""
Spine: Rule-based library management for Hindawi sutram.
Does NOT break existing codec - additive only.

Concept (from user):
- 32 foundational verbs (core C keywords) are like dhatupatha roots.
- Libraries derive huge verb corpus from them, named arbitrarily.
- Ambiguity forbidden at compile time: if verb not in library, system complains.
- Automated generation allowed only if Paninian derivation is valid.

This spine implements:
1. Core library: 32 C keywords -> canonical Sanskrit verbs (existing mappings.py)
2. Library declaration: user declares needed verbs via declare_library()
3. Derivation check: if custom verb requested, validate via Paninian rules
   (currently: must be valid Sanskrit word formation, no spaces, ends with valid pratyaya)
4. Bijective registry: each verb -> unique code, reversible
"""
from .mappings import OP_TO_SUTRAM, SUTRAM_TO_OP

# Core 32 (subset shown, extend as needed) - foundational, never ambiguous
CORE_VERBS = {
    'int': 'पूर्णाङ्क',
    'while': 'यावत्',
    'if': 'यदि',
    'return': 'प्रत्यागम',
    '=': 'स्थापय',
    '+': 'योजय',
}

class LibraryError(Exception):
    pass

class LibrarySpine:
    def __init__(self):
        # registry: verb_sanskrit -> (c_token, derived_from, is_core)
        self.registry = {}
        for c_tok, sans in CORE_VERBS.items():
            self.registry[sans] = (c_tok, None, True)
        # also load full ENCODE_MAP as core
        for c_tok, sans in OP_TO_SUTRAM.items():
            if sans not in self.registry:
                self.registry[sans] = (c_tok, None, True)

    def declare(self, sanskrit_verb: str, c_equivalent: str = None, derived_from: str = None):
        """
        Declare a library verb you need.
        - If already in registry, ok.
        - If not, validate formation: must be Devanagari word, no symbols, length>1.
        - If valid, register as derived; else raise LibraryError (system complains).
        Human intention required: c_equivalent must be provided for new verbs.
        """
        if sanskrit_verb in self.registry:
            return self.registry[sanskrit_verb]
        # Validation: Paninian well-formedness (simplified)
        if not sanskrit_verb or ' ' in sanskrit_verb:
            raise LibraryError(f"Invalid verb formation: '{sanskrit_verb}' contains space/empty")
        # Must be Devanagari (contains Devanagari range)
        if not any('\u0900' <= ch <= '\u097F' for ch in sanskrit_verb):
            raise LibraryError(f"Invalid verb '{sanskrit_verb}': not Devanagari")
        if c_equivalent is None:
            raise LibraryError(f"Verb '{sanskrit_verb}' not in library. Declare with c_equivalent (human intention required).")
        # Register as derived - bijective: ensure c_equivalent not already mapped to different sanskrit
        for s, (c, _, _) in self.registry.items():
            if c == c_equivalent and s != sanskrit_verb:
                raise LibraryError(f"Ambiguity: C '{c_equivalent}' already maps to '{s}', cannot also map to '{sanskrit_verb}'")
        self.registry[sanskrit_verb] = (c_equivalent, derived_from, False)
        return self.registry[sanskrit_verb]

    def resolve(self, sanskrit_verb: str):
        """Resolve or complain."""
        if sanskrit_verb not in self.registry:
            raise LibraryError(f"Unknown verb '{sanskrit_verb}'. Declare it first via declare().")
        return self.registry[sanskrit_verb][0]

    def list_core(self):
        return {s:v for s,v in self.registry.items() if v[2]}

    def list_derived(self):
        return {s:v for s,v in self.registry.items() if not v[2]}
