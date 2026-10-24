"""The one IDE of the chandah notebook. It is Hindawi's notebook IDE (nb_ide.ide in Hindawi 2026.10), with every one of
its actions kept and its own helpers used (languages, programs, hin, from_english), and chandah's added: raise the program
to chandah, lower chandah back to compilable Sanskrit C, and check every path there and back, built and run by Hindawi.
© 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI."""
import sys, tempfile
from pathlib import Path

from . import core


def ide(lang="sanskrit"):
    import ipywidgets as w
    from IPython.display import display, FileLink
    import nb_ide                                   # Hindawi's own, on the path once Installation has run
    langs = nb_ide.languages()
    L = w.Dropdown(options=langs, value=lang if lang in langs else langs[0], description="Language")
    S = w.ToggleButtons(options=[(t, e) for t, e in nb_ide.SHAILIS], value=".c")
    sec = w.Dropdown(description="Section"); prog = w.Dropdown(description="Program", layout=w.Layout(width="420px"))
    ed = w.Textarea(layout=w.Layout(width="99%", height="300px"))
    given = w.Textarea(placeholder="input for the program", layout=w.Layout(width="49%", height="100px"))
    shown = w.Textarea(placeholder="output", layout=w.Layout(width="49%", height="100px"))
    view = w.Output(layout=w.Layout(width="99%", border="1px solid #bbb"))
    up = w.FileUpload(multiple=False, description="Upload"); cur = {}
    numerals = w.Dropdown(options=core.NUMERALS, value="katapayadi", description="Numerals", layout=w.Layout(width="230px"))
    structure = w.Dropdown(options=[("none", None)] + [(s, s) for s in core.STRUCTURES if s], value="chhandas_anushtubh",
                           description="Structure", layout=w.Layout(width="300px"))
    sandhi = w.Checkbox(value=True, description="sandhi", indent=False, layout=w.Layout(width="90px"))
    ch = w.Textarea(placeholder="chandah: Raise to chandah writes it here; Lower brings it back into the editor",
                    layout=w.Layout(width="99%", height="200px"))
    state = {}

    def tmp():
        f = Path(tempfile.gettempdir()) / ("hindawi_program" + S.value)
        if S.value == ".java" and prog.value:
            f = Path(tempfile.gettempdir()) / Path(str(prog.value)).name
        f.write_text(ed.value, encoding="utf-8"); return f

    def fill(*_):
        cur.clear(); cur.update(nb_ide.programs(L.value, S.value)); sec.options = list(cur) or ["(none yet)"]; pick()

    def pick(*_):
        prog.options = [(p.name, p) for p in cur.get(sec.value, [])]
        load()

    def load(*_):
        if prog.value:
            t = Path(prog.value).read_text(encoding="utf-8")
            if (nb_ide.H / "samples") in Path(prog.value).parents:     # an English program: brought into the language as it opens
                t = nb_ide.from_english(t, S.value, L.value)
            ed.value = t; given.value = nb_ide.GIVEN.get(S.value, ""); shown.value = ""

    def act(f):
        def h(_):
            shown.value = "working ..."
            try:
                f()
            except Exception as e:                       # a button never leaves a trace of Python behind it
                shown.value = f"{type(e).__name__}: {e}"
        return h

    def run_():
        shown.value = nb_ide.hin("run", L.value, tmp(), given=given.value) or "(no output)"

    def stages_():
        view.clear_output()
        with view:
            print(nb_ide.hin("stages", L.value, tmp()))
        shown.value = "the stages are shown below"

    def host_():
        shown.value = nb_ide.hin("host", L.value, tmp())

    def english_():
        ed.value = nb_ide.from_english(ed.value, S.value, L.value); shown.value = f"brought into {L.value}"

    def new_():
        ed.value = given.value = shown.value = ch.value = ""; view.clear_output(); state.clear()

    def download_():
        f = Path("program" + S.value); f.write_text(ed.value, encoding="utf-8")
        if "google.colab" in sys.modules:
            from google.colab import files; files.download(str(f))
        else:
            with view:
                display(FileLink(str(f)))
        shown.value = f"saved as {f}"

    def upload_(c):
        v = up.value
        for item in (v if isinstance(v, (list, tuple)) else v.values()):
            ed.value = bytes(item["content"]).decode("utf-8", "replace")

    def _chandah_ready():
        if L.value != "sanskrit" or S.value not in (".c", ".cpp"):
            shown.value = "chandah carries Sanskrit C and C++: choose sanskrit, and C or C++"
            return False
        return True

    def raise_():
        if _chandah_ready():
            text, meta = core.raise_(ed.value, numerals.value, structure.value, sandhi.value)
            ch.value, state["meta"] = text, meta
            shown.value = f"raised to chandah ({core.path_name(numerals.value, structure.value, sandhi.value)})"

    def lower_():
        if "meta" not in state:
            shown.value = "raise a program first: lowering uses what raising recorded"; return
        ed.value = core.lower(ch.value.rstrip("\n"), state["meta"])
        shown.value = "lowered into the editor as compilable Sanskrit C; ▶ Build and run builds it"

    def check_():
        if not _chandah_ready():
            return
        lowered, report = core.check_paths(ed.value)
        bad = [(p, pr) for p, pr in report if pr]
        res = core.compile_compare(ed.value, lowered or "", S.value, given.value)
        view.clear_output()
        with view:
            print(f"{len(report) - len(bad)} of {len(report)} paths there and back exactly")
            for p, pr in bad:
                print(f"   {core.path_name(*p)}: {'; '.join(pr)}")
            if res is None:
                print("compile: Hindawi is not here")
            else:
                same, ra, rb = res
                print(f"built and run by Hindawi, original (exit {ra[0]}) and lowered (exit {rb[0]}): "
                      + ("the same output" if same else "NOT the same"))
                print(rb[1])
        shown.value = "every path checked: see below"

    L.observe(fill, "value"); S.observe(fill, "value"); sec.observe(pick, "value"); prog.observe(load, "value"); up.observe(upload_, "value")
    acts = [("▶ Build and run", run_), ("Stages", stages_), ("Host program", host_), ("From English", english_), ("New", new_), ("Download", download_)]
    bar = w.HBox([w.Button(description=n, layout=w.Layout(width="auto"), button_style="success" if i == 0 else "") for i, (n, _) in enumerate(acts)] + [up])
    for b, (_, f) in zip(bar.children, acts):
        b.on_click(act(f))
    chandah_acts = [("⇧ Raise to chandah", raise_), ("⇩ Lower to Sanskrit C", lower_), ("✓ Check every path", check_)]
    chandah_bar = w.HBox([numerals, structure, sandhi] + [w.Button(description=n, layout=w.Layout(width="auto"),
                                                                    button_style="info") for n, _ in chandah_acts])
    for b, (_, f) in zip(chandah_bar.children[3:], chandah_acts):
        b.on_click(act(f))
    fill()
    display(w.VBox([w.HBox([L]), S, w.HBox([sec, prog]), bar, ed, chandah_bar, ch, w.HBox([given, shown]), view]))
