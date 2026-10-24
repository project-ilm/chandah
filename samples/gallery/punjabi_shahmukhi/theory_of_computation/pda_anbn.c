#ضمن <stdio.h>
/* pushdown automata: accept a^n b^n (n >= 1) with a stack, reading a's then b's */
صحيح مندا(ثابت حرف *لفظ) {
  حرف تھبا[64]; صحيح چوٹی = 0, state = 0, index = 0;           /* state 0 reads a's, state 1 reads b's */
  لكل (; لفظ[index]; index++) {
    إذا (state == 0 && لفظ[index] == 'a') تھبا[چوٹی++] = 'A';
    وإلا إذا (لفظ[index] == 'b' && چوٹی > 0 && تھبا[چوٹی - 1] == 'A') { state = 1; چوٹی--; }
    وإلا أرجع 0;
  }
  أرجع state == 1 && چوٹی == 0;
}
صحيح مکھ(فراغ) { لکھو("%d %d %d %d\n", مندا("ab"), مندا("aaabbb"), مندا("aabbb"), مندا("abab")); أرجع 0; }
