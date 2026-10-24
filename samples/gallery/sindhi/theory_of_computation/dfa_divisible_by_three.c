#ضمن <stdio.h>
/* a DFA over binary strings that accepts multiples of three */
صحيح قبولي(ثابت حرف *لفظ) {
  صحيح state = 0;
  لكل (صحيح index = 0; لفظ[index]; index++) state = (state * 2 + (لفظ[index] - '0')) % 3;
  أرجع state == 0;
}
صحيح مکيه(فراغ) { لکو("%d %d %d %d\n", قبولي("110"), قبولي("111"), قبولي("1001"), قبولي("0")); أرجع 0; }
