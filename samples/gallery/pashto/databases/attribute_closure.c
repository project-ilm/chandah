#ضمن <stdio.h>
/* normal forms: the closure of a set of attributes under functional dependencies; attributes A..F are bits */
صحيح اصلي(فراغ) {
  صحيح کیڼ_اړخ[] = {1 | 2, 2 | 4, 8, 16}, ښی_اړخ[] = {4, 8, 16, 32}, تړون = 1 | 2, بدل_شوی = 1;   /* AB->C, BC->D, D->E, E->F */
  طالما (بدل_شوی) {
    بدل_شوی = 0;
    لكل (صحيح index = 0; index < 4; index++)
      إذا ((تړون & کیڼ_اړخ[index]) == کیڼ_اړخ[index] && (تړون | ښی_اړخ[index]) != تړون) { تړون |= ښی_اړخ[index]; بدل_شوی = 1; }
  }
  لكل (صحيح بټ = 0; بټ < 6; بټ++) إذا (تړون & (1 << بټ)) چاپ_کړه("%c", 'A' + بټ);
  چاپ_کړه("\n");
  أرجع 0;
}
