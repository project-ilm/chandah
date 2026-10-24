#ضمن <stdio.h>
#ضمن <ctype.h>
/* a hand-written lexer: identifiers, numbers and operators */
صحيح مکيه(فراغ) {
  حرف ذريعو[] = "total = count1 + 42 * rate;";
  صحيح index = 0, ٽوڪن = 0;
  طالما (ذريعو[index]) {
    إذا (خال_آهي(ذريعو[index])) { index++; استمر; }
    صحيح شروعات = index;
    إذا (اکر_آهي(ذريعو[index])) { طالما (اکر_يا_انگ(ذريعو[index])) index++; لکو("ID "); }
    وإلا إذا (انگ_آهي(ذريعو[index])) { طالما (انگ_آهي(ذريعو[index])) index++; لکو("NUM "); }
    وإلا { index++; لکو("OP "); }
    ٽوڪن++;
    (فراغ)شروعات;
  }
  لکو("\n%d\n", ٽوڪن);
  أرجع 0;
}
