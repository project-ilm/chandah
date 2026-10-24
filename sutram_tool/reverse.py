# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. sutram v11, kept as given apart from these two
# lines, the corrections in docs/CORRECTIONS.md and the completion below its marker (docs/COMPLETION.md).
from .mappings import SUTRAM_TO_OP, WORD_PARIBHASHIT, WORD_ANU, WORD_PURNA, WORD_SUCHAK, WORD_NIRDESHAK, WORD_AKAR, WORD_AKARHEEN, WORD_UDDHARAN_ARAMBHA, WORD_UDDHARAN_ANTA, WORD_PURVANIRDESH, WORD_AAVESHA, WORD_SAMUHARAMBHA, WORD_SAMUHANTA, HEADER_REVERSE, FORMAT_REVERSE, sutram_to_ident
from .numerals import to_latin_digits
from .katapayadi import decode_katapayadi

OP_WORDS = set(SUTRAM_TO_OP.keys())

def _sutram_num_to_latin(w: str) -> str:
    # v1: devanagari digits
    if w and w[0] in '०१२३४५६७८९':
        return to_latin_digits(w)
    # v2: katapayadi - try decode, if yields digits return it
    try:
        d = decode_katapayadi(w, reverse_order=True)
        if d and d.isdigit():
            return d
    except:
        pass
    return w

def words_to_expr(words):
    if not words:
        return ""
    # v2 katapayadi numbers are marked as संख्याङ्क <word>
    if "संख्याङ्क" in words:
        # Replace each occurrence with decoded latin digit placeholder
        new_words=[]
        i=0
        while i < len(words):
            if words[i]=="संख्याङ्क" and i+1 < len(words):
                try:
                    d=decode_katapayadi(words[i+1], reverse_order=True)
                    if d.isdigit():
                        new_words.append(d)  # keep as latin for now, will be converted later? Keep latin
                        i+=2
                        continue
                except:
                    pass
            new_words.append(words[i]); i+=1
        words=new_words
    # grouping समूहारम्भ ... समूहान्त -> ( ... ) for precedence preservation
    if WORD_SAMUHARAMBHA in words:
        # avoid treating init-list here; init-list is handled in parse_sutram vardef branch
        # In expr context, collapse innermost groups
        while WORD_SAMUHARAMBHA in words and WORD_SAMUHANTA in words:
            try:
                end_idx = words.index(WORD_SAMUHANTA)
            except:
                break
            start_idx = -1
            for ii in range(end_idx-1, -1, -1):
                if words[ii]==WORD_SAMUHARAMBHA:
                    start_idx=ii; break
            if start_idx==-1:
                break
            inner = words[start_idx+1:end_idx]
            inner_expr = words_to_expr(inner)
            words = words[:start_idx] + [f"({inner_expr})"] + words[end_idx+1:]
        if len(words)==1 and words[0].startswith("(") and words[0].endswith(")"):
            return words[0]
    if WORD_UDDHARAN_ARAMBHA in words:
        s_idx=words.index(WORD_UDDHARAN_ARAMBHA)
        try:
            e_idx=words.index(WORD_UDDHARAN_ANTA)
        except:
            e_idx=len(words)-1
        inner=words[s_idx+1:e_idx]
        # specific for example
        if inner==["प्रारूपपूर्णाङ्क","प्रारूपपूर्णाङ्क","नूतनपङ्क्ति"]:
            s='"%d %d\\n"'
        else:
            mapped=[FORMAT_REVERSE.get(w,w) for w in inner]
            s='"'+" ".join(mapped)+'"'
        after=words[e_idx+1:] if e_idx+1 < len(words) else []
        if not after and s_idx==0:
            return s
        # if part of call, fall through to call handling below by reconstructing
        # For now, if this was called for full call line, handle in call section
        # Return marker to let caller know
        # Simplify: if s_idx>0, this is call with leading name
        pass
    if WORD_SUCHAK in words:
        si=words.index(WORD_SUCHAK)
        base=sutram_to_ident(words[si-1])
        idx_expr=words_to_expr([words[si+1]])
        left=f"{base}[{idx_expr}]"
        rest=words[si+2:]
        if not rest:
            return left
        if rest[0] in OP_WORDS:
            op=SUTRAM_TO_OP[rest[0]]
            if op=="*_bin": op="*"
            right=words_to_expr(rest[1:])
            return f"{left} {op} {right}"
        return left
    for idx,w in enumerate(words):
        if w in OP_WORDS:
            op=SUTRAM_TO_OP[w]
            if op=="*_bin": op="*"
            if w=="स्थापय": op="="
            left_w=words[:idx]; right_w=words[idx+1:]
            left=words_to_expr(left_w) if left_w else ""
            right=words_to_expr(right_w) if right_w else ""
            return f"{left} {op} {right}".strip()
    if len(words)==1:
        w=words[0]
        if w and w[0] in "०१२३४५६७८९":
            return to_latin_digits(w)
        # latin digits from katapayadi marker processing
        if w.isdigit():
            return w
        return sutram_to_ident(w)
    # call handling for द्विमान
    if words[0]=="द्विमानयोजकअन्वेषणम्" and len(words)==4:
        a1=sutram_to_ident(words[1]); a2=to_latin_digits(words[2]); a3=to_latin_digits(words[3])
        return f"{sutram_to_ident(words[0])}({a1}, {a2}, {a3})"
    if words[0]=="प्रारूपयोजकलिख":
        # प्रारूपयोजकलिख उद्धरणारम्भ ... उद्धरणान्त द्विमान... ...
        try:
            s_idx=words.index(WORD_UDDHARAN_ARAMBHA)
            e_idx=words.index(WORD_UDDHARAN_ANTA)
            s='"%d %d\\n"'
            remaining=words[e_idx+1:]
            args=[s]
            idx=0
            while idx < len(remaining):
                if remaining[idx]=="द्विमानयोजकअन्वेषणम्":
                    # parse: name, ident, num, num ; nums may be संख्याङ्क <w> or devanagari
                    p=idx+1
                    a1=sutram_to_ident(remaining[p]); p+=1
                    def _parse_num():
                        nonlocal p
                        if p < len(remaining) and remaining[p]=="संख्याङ्क":
                            d=decode_katapayadi(remaining[p+1], reverse_order=True); p+=2; return d
                        else:
                            d=to_latin_digits(remaining[p]); p+=1; return d
                    a2=_parse_num(); a3=_parse_num()
                    args.append(f"{sutram_to_ident('द्विमानयोजकअन्वेषणम्')}({a1}, {a2}, {a3})")
                    idx=p
                else:
                    idx+=1
            return f"{sutram_to_ident(words[0])}({', '.join(args)})"
        except:
            pass
    conv=[]
    for w in words:
        if w and w[0] in "०१२३४५६७८९":
            conv.append(to_latin_digits(w))
        else:
            conv.append(sutram_to_ident(w))
    return " ".join(conv)

def words_to_stmt(words):
    if not words:
        return ";"
    if words[0]=="प्रत्यागम":
        expr=words_to_expr(words[1:])
        return f"प्रत्यागम {expr};"
    expr=words_to_expr(words)
    return f"{expr};"

def parse_sutram(sutram_text: str) -> str:
    lines=[l.strip() for l in sutram_text.strip().split("\n") if l.strip()!='']
    out_lines=[]
    for line in lines:
        # skip chhandas empty breaks - already filtered
        words=line.split()
        if not words: continue
        # Skip pure chhandas grouping? No, words are same.
        # Detect shloka breaks: our chhandas groups but words remain.
        # If line was from chhandas formatter, it is still valid sutram words.
        if words[0]==WORD_PURVANIRDESH:
            header_key=tuple(words[2:])
            orig=HEADER_REVERSE.get(header_key, "".join(words[2:]))
            out_lines.append(f"#अन्तर्भाव {orig}")
            continue
        if words[0]==WORD_PARIBHASHIT:
            if words[-1]==WORD_ANU:
                ret=words[1]; name=sutram_to_ident(words[2]); rest=words[3:-1]
                if rest==["शून्य"]:
                    params_str="शून्य"
                else:
                    params=[]; j=0
                    while j < len(rest):
                        typ=rest[j]; j+=1
                        if j < len(rest) and rest[j]==WORD_NIRDESHAK:
                            j+=1; pname=sutram_to_ident(rest[j]); j+=1
                            params.append(f"{typ} {pname}[]")
                        else:
                            pname=sutram_to_ident(rest[j]); j+=1
                            params.append(f"{typ} {pname}")
                    params_str=", ".join(params)
                out_lines.append(f"{ret} {name}({params_str}) {{")
                continue
            else:
                typ=words[1]; name=sutram_to_ident(words[2]); idx=3; is_array=False
                if idx < len(words) and words[idx] in (WORD_AKARHEEN, WORD_AKAR):
                    is_array=True; idx+=1
                if idx < len(words) and words[idx]=="स्थापय":
                    idx+=1
                    if idx < len(words) and words[idx]==WORD_SAMUHARAMBHA:
                        idx+=1; nums=[]
                        while idx < len(words) and words[idx]!=WORD_SAMUHANTA:
                            if words[idx]=="संख्याङ्क" and idx+1 < len(words):
                                try:
                                    d=decode_katapayadi(words[idx+1], reverse_order=True)
                                    nums.append(d); idx+=2; continue
                                except:
                                    pass
                            # v1 devanagari
                            if words[idx][0] in "०१२३४५६७८९":
                                nums.append(to_latin_digits(words[idx])); idx+=1
                            else:
                                # fallback: try words_to_expr
                                nums.append(words_to_expr([words[idx]])); idx+=1
                        init="{"+", ".join(nums)+"}"
                        arr="[]" if is_array else ""
                        out_lines.append(f"{typ} {name}{arr} = {init};")
                    else:
                        expr=words_to_expr(words[idx:])
                        arr="[]" if is_array else ""
                        out_lines.append(f"{typ} {name}{arr} = {expr};")
                else:
                    arr="[]" if is_array else ""
                    out_lines.append(f"{typ} {name}{arr};")
                continue
        if words[0]=="यावत्":
            anu_idx=words.index(WORD_ANU)
            cond=words_to_expr(words[1:anu_idx])
            out_lines.append(f"यावत् ({cond}) {{")
            continue
        if words[0]=="यदि":
            cond_ops={"समम्","नसमम्","अल्पतरम्","अधिकतरम्","अल्पतरंवासमम्","अधिकतरंवासमम्"}
            cond_end=-1
            for k,w in enumerate(words):
                if w in cond_ops:
                    cond_end=k+2; break
            cond=words_to_expr(words[1:cond_end])
            rest=words[cond_end:]
            if "अन्यथा" in rest:
                ai=rest.index("अन्यथा")
                then_src=words_to_stmt(rest[:ai]); else_src=words_to_stmt(rest[ai+1:])
                out_lines.append(f"यदि ({cond}) {then_src} अन्यथा {else_src}")
            else:
                then_src=words_to_stmt(rest)
                out_lines.append(f"यदि ({cond}) {then_src}")
            continue
        if words[0]==WORD_PURNA:
            out_lines.append("}")
            continue
        if words[0]=="प्रत्यागम":
            expr=words_to_expr(words[1:]) if len(words)>1 else ""
            out_lines.append(f"प्रत्यागम {expr};".strip())
            continue
        expr=words_to_expr(words)
        out_lines.append(f"{expr};")
    return "\n".join(out_lines)


# ===== chandah completion of sutram v11: from the complete base layer back to compilable source =====
# sutram_to_source(sutram) returns compilable C or C++ in the program's own language: every token back, one source
# line per sutram line, indented by its blocks. It needs nothing but the text. parse_sutram above is unchanged.
from .mappings import (WORD_TO_TOKEN, WORD_TO_LITERAL, NUMBER_CHAR_WORDS, HEADER_WORD_TO_NAME, WORD_EMPTY_LINE,
                       WORD_NUMBER, WORD_NUMBER_FORM, WORD_NUMBER_FORM_END, WORD_NATIVE_DIGITS, WORD_STRING_BEGIN,
                       WORD_STRING_END, WORD_CHAR_BEGIN, WORD_CHAR_END, WORD_LITERAL_PREFIX, WORD_HEADER_BEGIN,
                       WORD_HEADER_END, WORD_MACRO_PAREN, WORD_SPLICE, WORD_NAME, WORD_LITERALLY, WORD_CODEPOINT,
                       WORD_PARIBHASHIT, WORD_AAVESHA, INCLUDE_DIRECTIVE, word_to_name)

_NUMBER_WORD_TO_CHAR = {w: c for c, w in NUMBER_CHAR_WORDS.items()}


def _is_deva_digits(w):
    return bool(w) and all("\u0966" <= c <= "\u096F" for c in w)


def _digits_back(w):
    return to_latin_digits(w) if _is_deva_digits(w) else decode_katapayadi(w, reverse_order=True)


def _content_back(ws, i, end):
    out = []
    while ws[i] != end:
        w = ws[i]
        if w == WORD_LITERALLY:
            out.append(ws[i + 1]); i += 2
        elif w == WORD_NUMBER:
            out.append(_digits_back(ws[i + 1])); i += 2
        elif w == WORD_CODEPOINT:
            out.append(chr(int(_digits_back(ws[i + 2])))); i += 3
        elif w in WORD_TO_LITERAL:
            out.append(WORD_TO_LITERAL[w]); i += 1
        else:
            out.append(w); i += 1
    return "".join(out), i + 1


def _number_back(ws, i):
    out = []
    while ws[i] != WORD_NUMBER_FORM_END:
        w = ws[i]
        if w == WORD_NATIVE_DIGITS:
            out.append(ws[i + 1]); i += 2; continue
        if w in _NUMBER_WORD_TO_CHAR:
            out.append(_NUMBER_WORD_TO_CHAR[w])
        elif w.isascii() or (w.isalpha() and not _is_deva_digits(w) and not all("\u0915" <= c <= "\u0939" for c in w)):
            out.append(w)
        else:
            out.append(_digits_back(w))
        i += 1
    return "".join(out), i + 1


def sutram_to_tokens(sutram: str):
    lines = []
    for raw in sutram.split("\n"):
        ws = raw.split()
        if ws == [WORD_EMPTY_LINE]:
            lines.append([]); continue
        toks, i, prefix = [], 0, ""
        while i < len(ws):
            w = ws[i]
            if w == WORD_PARIBHASHIT:
                i += 1
            elif w == WORD_NAME:
                toks.append(("ID", word_to_name(ws[i + 1]))); i += 2
            elif w == WORD_NUMBER:
                toks.append(("NUM", _digits_back(ws[i + 1]))); i += 2
            elif _is_deva_digits(w):
                toks.append(("NUM", to_latin_digits(w))); i += 1
            elif w == WORD_NUMBER_FORM:
                text, i = _number_back(ws, i + 1); toks.append(("NUM", text))
            elif w == WORD_LITERAL_PREFIX:
                prefix = ws[i + 1]; i += 2
            elif w == WORD_STRING_BEGIN:
                text, i = _content_back(ws, i + 1, WORD_STRING_END); toks.append(("STR", prefix + '"' + text + '"')); prefix = ""
            elif w == WORD_CHAR_BEGIN:
                text, i = _content_back(ws, i + 1, WORD_CHAR_END); toks.append(("CHR", prefix + "'" + text + "'")); prefix = ""
            elif w == WORD_HEADER_BEGIN:
                text, i = _content_back(ws, i + 1, WORD_HEADER_END); toks.append(("HEADER", "<" + text + ">"))
            elif w in HEADER_WORD_TO_NAME:
                toks.append(("HEADER", HEADER_WORD_TO_NAME[w])); i += 1
            elif w == WORD_AAVESHA:
                toks.append(("ID", INCLUDE_DIRECTIVE)); i += 1
            elif w == WORD_MACRO_PAREN:
                toks.append(("GLUE", "(")); i += 1
            elif w == WORD_SPLICE:
                toks.append(("SPLICE", "\\")); i += 1
            elif w in WORD_TO_TOKEN:
                toks.append(("OP", WORD_TO_TOKEN[w])); i += 1
            else:
                toks.append(("ID", word_to_name(w))); i += 1
        lines.append(toks)
    return lines


def tokens_to_source(lines) -> str:
    out, depth = [], 0
    for toks in lines:
        if not toks:
            out.append(""); continue
        first = toks[0][1]
        shown = max(0, depth - 1) if first == "}" else depth
        s = ""
        for idx, (kind, text) in enumerate(toks):
            if idx == 0:
                s = text
            elif kind == "GLUE" or (idx == 1 and first == "#" and toks[0][0] == "OP"):
                s += text
            elif kind == "SPLICE":
                s += " \\"
            else:
                s += " " + text
        out.append(("" if first == "#" else "    " * shown) + s)
        depth = max(0, depth + sum(1 for k, t in toks if k == "OP" and t == "{") - sum(1 for k, t in toks if k == "OP" and t == "}"))
    return "\n".join(out) + "\n"


def sutram_to_source(sutram: str) -> str:
    return tokens_to_source([[(k, t) for k, t in line] for line in sutram_to_tokens(sutram)])
