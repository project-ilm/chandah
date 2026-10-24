#ضمن <stdio.h>
/* intermediate code generation: three-address code for a = b * c + b * d, with common subexpression reuse shown */
صحيح مکھ(فراغ) {
  ثابت حرف *کوڈ[] = {"t1 = b * c", "t2 = b * d", "t3 = t1 + t2", "a = t3"};
  لكل (صحيح index = 0; index < 4; index++) لکھو("%s\n", کوڈ[index]);
  أرجع 0;
}
