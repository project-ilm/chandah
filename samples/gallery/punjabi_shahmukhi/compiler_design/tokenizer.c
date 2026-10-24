#ضمن <stdio.h>
#ضمن <ctype.h>
/* a hand-written lexer: identifiers, numbers and operators */
صحيح مکھ(فراغ) {
  حرف سروت[] = "total = count1 + 42 * rate;";
  صحيح index = 0, ٹوکن = 0;
  طالما (سروت[index]) {
    إذا (خلا_اے(سروت[index])) { index++; استمر; }
    صحيح شروع = index;
    إذا (حرف_اے(سروت[index])) { طالما (حرف_یا_ہندسہ(سروت[index])) index++; لکھو("ID "); }
    وإلا إذا (ہندسہ_اے(سروت[index])) { طالما (ہندسہ_اے(سروت[index])) index++; لکھو("NUM "); }
    وإلا { index++; لکھو("OP "); }
    ٹوکن++;
    (فراغ)شروع;
  }
  لکھو("\n%d\n", ٹوکن);
  أرجع 0;
}
