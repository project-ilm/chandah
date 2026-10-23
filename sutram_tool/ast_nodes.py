# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these two lines and the corrections recorded in docs/CORRECTIONS.md.
from dataclasses import dataclass
from typing import List, Optional, Union

@dataclass
class Param:
    typ: str
    name: str
    is_array: bool = False

@dataclass
class FuncDef:
    ret: str
    name: str
    params: List[Param]
    body: list

@dataclass
class VarDef:
    typ: str
    name: str
    is_array: bool = False
    is_array_empty: bool = False
    init: Optional[object] = None
    init_list: Optional[list] = None

@dataclass
class While:
    cond: object
    body: list

@dataclass
class If:
    cond: object
    then_b: list
    else_b: Optional[list] = None

@dataclass
class Return:
    expr: Optional[object]

@dataclass
class ExprStmt:
    expr: object

@dataclass
class BinOp:
    left: object
    op: str
    right: object

@dataclass
class UnaryOp:
    op: str
    expr: object

@dataclass
class Call:
    name: str
    args: list

@dataclass
class Index:
    base: str
    index: object

@dataclass
class Var:
    name: str

@dataclass
class Num:
    value: str

@dataclass
class StrLit:
    value: str
