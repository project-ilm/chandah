#ضمن <stdio.h>
/* a DFA over binary strings that accepts multiples of three */
صحيح میپذیرد(ثابت حرف *کلمه) {
  صحيح state = 0;
  لكل (صحيح index = 0; کلمه[index]; index++) state = (state * 2 + (کلمه[index] - '0')) % 3;
  أرجع state == 0;
}
صحيح اصلی(فراغ) { چاپ_کن("%d %d %d %d\n", میپذیرد("110"), میپذیرد("111"), میپذیرد("1001"), میپذیرد("0")); أرجع 0; }
