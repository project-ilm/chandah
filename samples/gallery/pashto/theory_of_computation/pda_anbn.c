#ضمن <stdio.h>
/* pushdown automata: accept a^n b^n (n >= 1) with a stack, reading a's then b's */
صحيح مني(ثابت حرف *کلمه) {
  حرف ټولګه[64]; صحيح څوکه = 0, state = 0, index = 0;           /* state 0 reads a's, state 1 reads b's */
  لكل (; کلمه[index]; index++) {
    إذا (state == 0 && کلمه[index] == 'a') ټولګه[څوکه++] = 'A';
    وإلا إذا (کلمه[index] == 'b' && څوکه > 0 && ټولګه[څوکه - 1] == 'A') { state = 1; څوکه--; }
    وإلا أرجع 0;
  }
  أرجع state == 1 && څوکه == 0;
}
صحيح اصلي(فراغ) { چاپ_کړه("%d %d %d %d\n", مني("ab"), مني("aaabbb"), مني("aabbb"), مني("abab")); أرجع 0; }
