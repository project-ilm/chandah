# © 1993–2026 Abhishek Choudhary. All rights reserved. AyeAI. Written by Meta AI under his direction (sutram v11),
# kept as given apart from these two lines and the corrections recorded in docs/CORRECTIONS.md.
from .lexer import lex
from .ast_nodes import Param, FuncDef, VarDef, While, If, Return, ExprStmt, BinOp, UnaryOp, Call, Index, Var, Num, StrLit

class Parser:
    def __init__(self, toks):
        self.toks = toks
        self.i = 0
    def peek(self):
        return self.toks[self.i] if self.i < len(self.toks) else (None,None)
    def next(self):
        t = self.peek(); self.i+=1; return t
    def expect(self, val):
        k,v = self.next()
        assert v==val, f"expected {val} got {v}"
        return v
    def parse_program(self):
        funcs=[]; preprocs=[]
        while self.i < len(self.toks):
            k,v = self.peek()
            if v=="#अन्तर्भाव" or k=="PREPROC":
                preprocs.append(self.parse_preproc())
            else:
                funcs.append(self.parse_funcdef())
        return preprocs, funcs
    def parse_preproc(self):
        self.expect("#अन्तर्भाव")
        k,v = self.peek()
        path=""
        if v=="<":
            self.next()
            parts=[]
            while True:
                k2,v2=self.next()
                parts.append(v2)
                k3,v3=self.peek()
                if v3==">":
                    self.next(); break
            path="<"+"".join(parts)+">"
        else:
            k2,v2=self.next(); path=v2
        return path
    def parse_funcdef(self):
        _, typ = self.next()
        _, name = self.next()
        self.expect("(")
        params=[]
        k,v=self.peek()
        if v=="शून्य":
            self.next()
        elif v!=")":
            while True:
                _, ptyp = self.next()
                _, pname = self.next()
                is_array=False
                k3,v3=self.peek()
                if v3=="[":
                    self.next(); self.expect("]"); is_array=True
                params.append(Param(ptyp,pname,is_array))
                k4,v4=self.peek()
                if v4==",":
                    self.next(); continue
                break
        self.expect(")")
        self.expect("{")
        body=self.parse_stmts()
        self.expect("}")
        return FuncDef(typ,name,params,body)
    def parse_stmts(self):
        stmts=[]
        while True:
            k,v=self.peek()
            if v=="}" or v is None:
                break
            stmts.append(self.parse_stmt())
        return stmts
    def parse_stmt(self):
        k,v=self.peek()
        if v in ("पूर्णाङ्क","शून्य"):
            return self.parse_vardef()
        if v=="यावत्":
            return self.parse_while()
        if v=="यदि":
            return self.parse_if()
        if v=="प्रत्यागम":
            return self.parse_return()
        e=self.parse_expr()
        k2,v2=self.peek()
        if v2==";":
            self.next()
        return ExprStmt(e)
    def parse_vardef(self):
        _, typ=self.next()
        defs=[]
        while True:
            _, name=self.next()
            is_array=False; is_empty=False
            k,v=self.peek()
            if v=="[":
                self.next(); self.expect("]"); is_array=True; is_empty=True
            init=None; init_list=None
            k2,v2=self.peek()
            if v2=="=":
                self.next()
                k3,v3=self.peek()
                if v3=="{":
                    self.next()
                    lst=[]
                    k4,v4=self.peek()
                    if v4!="}":
                        while True:
                            lst.append(self.parse_expr())
                            k5,v5=self.peek()
                            if v5==",":
                                self.next(); continue
                            break
                    self.expect("}")
                    init_list=lst
                else:
                    init=self.parse_expr()
            defs.append(VarDef(typ,name,is_array,is_empty,init,init_list))
            k6,v6=self.peek()
            if v6==",":
                self.next(); continue
            break
        k7,v7=self.peek()
        if v7==";":
            self.next()
        if len(defs)==1:
            return defs[0]
        else:
            return ("MULTI_VARDEF", defs)
    def parse_while(self):
        self.expect("यावत्")
        self.expect("(")
        cond=self.parse_expr()
        self.expect(")")
        self.expect("{")
        body=self.parse_stmts()
        self.expect("}")
        return While(cond,body)
    def parse_if(self):
        self.expect("यदि")
        self.expect("(")
        cond=self.parse_expr()
        self.expect(")")
        then_stmt=self.parse_stmt()
        then_b=self._stmt_to_list(then_stmt)
        else_b=None
        k,v=self.peek()
        if v=="अन्यथा":
            self.next()
            else_stmt=self.parse_stmt()
            else_b=self._stmt_to_list(else_stmt)
        return If(cond,then_b,else_b)
    def _stmt_to_list(self, s):
        if isinstance(s, tuple) and s[0]=="MULTI_VARDEF":
            return s[1]
        if isinstance(s, list):
            return s
        return [s]
    def parse_return(self):
        self.expect("प्रत्यागम")
        k,v=self.peek()
        if v==";":
            self.next(); return Return(None)
        e=self.parse_expr()
        k2,v2=self.peek()
        if v2==";":
            self.next()
        return Return(e)
    def parse_expr(self):
        return self.parse_assign()
    def parse_assign(self):
        left=self.parse_equality()
        k,v=self.peek()
        if v in ("=","+=","-=","*=","/=","%="):
            self.next()
            right=self.parse_assign()
            return BinOp(left,v,right)
        return left
    def parse_equality(self):
        e=self.parse_relational()
        while True:
            k,v=self.peek()
            if v in ("==","!="):
                self.next(); r=self.parse_relational(); e=BinOp(e,v,r)
            else: break
        return e
    def parse_relational(self):
        e=self.parse_add()
        while True:
            k,v=self.peek()
            if v in ("<",">","<=",">="):
                self.next(); r=self.parse_add(); e=BinOp(e,v,r)
            else: break
        return e
    def parse_add(self):
        e=self.parse_mul()
        while True:
            k,v=self.peek()
            if v in ("+","-"):
                self.next(); r=self.parse_mul(); e=BinOp(e,v,r)
            else: break
        return e
    def parse_mul(self):
        e=self.parse_unary()
        while True:
            k,v=self.peek()
            if v in ("*","/","%"):
                self.next(); r=self.parse_unary(); e=BinOp(e,v,r)
            else: break
        return e
    def parse_unary(self):
        k,v=self.peek()
        if v in ("-","!","&","*"):
            self.next()
            ex=self.parse_unary()
            if v=="*":
                return UnaryOp("*_deref", ex)
            if v=="&":
                return UnaryOp("&_addr", ex)
            return UnaryOp(v, ex)
        return self.parse_postfix()
    def parse_postfix(self):
        e=self.parse_primary()
        while True:
            k,v=self.peek()
            if v=="[":
                self.next(); idx=self.parse_expr(); self.expect("]"); e=Index(e.name if isinstance(e,Var) else str(e), idx)
            elif v=="(":
                self.next()
                args=[]
                k2,v2=self.peek()
                if v2!=")":
                    while True:
                        args.append(self.parse_expr())
                        k3,v3=self.peek()
                        if v3==",":
                            self.next(); continue
                        break
                self.expect(")")
                name = e.name if isinstance(e,Var) else ""
                e=Call(name,args)
            else:
                break
        return e
    def parse_primary(self):
        k,v=self.peek()
        if v=="(":
            self.next(); e=self.parse_expr(); self.expect(")"); return e
        if k=="NUMBER":
            self.next(); return Num(v)
        if k=="STRING":
            self.next(); return StrLit(v)
        if k=="IDENT":
            self.next(); return Var(v)
        raise Exception(f"unexpected primary {k}:{v}")

def parse_source(src: str):
    toks=lex(src)
    p=Parser(toks)
    preprocs, funcs=p.parse_program()
    def expand(stmts):
        out=[]
        for s in stmts:
            if isinstance(s, tuple) and s[0]=="MULTI_VARDEF":
                out.extend(s[1])
            elif isinstance(s, While):
                s.body=expand(s.body); out.append(s)
            elif isinstance(s, If):
                s.then_b=expand(s.then_b)
                if s.else_b: s.else_b=expand(s.else_b)
                out.append(s)
            else:
                out.append(s)
        return out
    for f in funcs:
        f.body=expand(f.body)
    return preprocs, funcs
