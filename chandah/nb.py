"""The chandah panel for the Hindawi notebooks, opened beside the IDE: choose or paste a program, see it through every
layer, then revert it and let Hindawi build and run both. © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI."""
import tempfile
from pathlib import Path

from . import core


def _programs(lang):
    """The IDE's own programs (Hindawi's nb_ide, on the path once the IDE cell has run), plus the practice files."""
    out = {}
    practice = sorted(Path("/content/hin").glob("*.c")) + sorted(Path("/content/hin").glob("*.cpp"))
    if practice:
        out["your practice programs"] = practice
    try:
        import nb_ide
        for ext in (".c", ".cpp"):
            for section, files in nb_ide.programs(lang, ext).items():
                if section.startswith("GATE"):
                    out.setdefault(section, []).extend(files)
    except Exception:
        pass
    return out


def panel(lang="sanskrit"):
    import ipywidgets as w
    from IPython.display import display
    progs = _programs(lang)
    options = [("(paste or upload a program)", "")] + [(f"{s} · {Path(f).name}", str(f)) for s, fs in progs.items() for f in fs]
    pick = w.Dropdown(options=options, description="Program", layout=w.Layout(width="520px"))
    up = w.FileUpload(multiple=False, description="Upload")
    text = w.Textarea(layout=w.Layout(width="100%", height="240px"))
    numerals = w.Dropdown(options=core.NUMERALS, value="katapayadi", description="Numerals")
    structure = w.Dropdown(options=[("none", None)] + [(s, s) for s in core.STRUCTURES if s], value="chhandas_anushtubh",
                           description="Structure")
    sandhi = w.Checkbox(value=True, description="sandhi")
    every = w.Button(description="Every layer", button_style="success")
    back = w.Button(description="Revert and compile")
    out = w.Output()
    ext = {"value": ".c"}

    def load(change):
        if change["new"]:
            ext["value"] = Path(change["new"]).suffix
            text.value = Path(change["new"]).read_text(encoding="utf-8")

    def uploaded(change):
        for name, item in _uploads(up):
            ext["value"] = Path(name).suffix or ".c"
            text.value = item.decode("utf-8")

    def show_every(_):
        out.clear_output()
        with out:
            print(core.stages_report(text.value)[0])

    def show_back(_):
        out.clear_output()
        with out:
            with tempfile.TemporaryDirectory() as d:
                f = Path(d) / ("program" + ext["value"])
                f.write_text(text.value, encoding="utf-8")
                print(core.revert_report(f, numerals.value, structure.value, sandhi.value)[0])

    pick.observe(load, names="value"); up.observe(uploaded, names="value")
    every.on_click(show_every); back.on_click(show_back)
    display(w.VBox([w.HBox([pick, up]), text, w.HBox([numerals, structure, sandhi]), w.HBox([every, back]), out]))


def _uploads(up):
    v = up.value
    if isinstance(v, dict):
        return [(name, item["content"]) for name, item in v.items()]
    return [(item["name"], bytes(item["content"])) for item in v]
