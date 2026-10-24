#ضمن <stdio.h>
/* normal forms: the closure of a set of attributes under functional dependencies; attributes A..F are bits */
صحيح مکيه(فراغ) {
  صحيح کاٻو[] = {1 | 2, 2 | 4, 8, 16}, ساڄو[] = {4, 8, 16, 32}, گهيرو = 1 | 2, بدليو = 1;   /* AB->C, BC->D, D->E, E->F */
  طالما (بدليو) {
    بدليو = 0;
    لكل (صحيح index = 0; index < 4; index++)
      إذا ((گهيرو & کاٻو[index]) == کاٻو[index] && (گهيرو | ساڄو[index]) != گهيرو) { گهيرو |= ساڄو[index]; بدليو = 1; }
  }
  لكل (صحيح ٻٽو_انگ = 0; ٻٽو_انگ < 6; ٻٽو_انگ++) إذا (گهيرو & (1 << ٻٽو_انگ)) لکو("%c", 'A' + ٻٽو_انگ);
  لکو("\n");
  أرجع 0;
}
