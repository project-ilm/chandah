#ضمن <stdio.h>
/* a DFA over binary strings that accepts multiples of three */
صحيح مندا(ثابت حرف *لفظ) {
  صحيح state = 0;
  لكل (صحيح index = 0; لفظ[index]; index++) state = (state * 2 + (لفظ[index] - '0')) % 3;
  أرجع state == 0;
}
صحيح مکھ(فراغ) { لکھو("%d %d %d %d\n", مندا("110"), مندا("111"), مندا("1001"), مندا("0")); أرجع 0; }
