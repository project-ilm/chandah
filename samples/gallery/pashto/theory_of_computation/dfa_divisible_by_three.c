#ضمن <stdio.h>
/* a DFA over binary strings that accepts multiples of three */
صحيح مني(ثابت حرف *کلمه) {
  صحيح state = 0;
  لكل (صحيح index = 0; کلمه[index]; index++) state = (state * 2 + (کلمه[index] - '0')) % 3;
  أرجع state == 0;
}
صحيح اصلي(فراغ) { چاپ_کړه("%d %d %d %d\n", مني("110"), مني("111"), مني("1001"), مني("0")); أرجع 0; }
