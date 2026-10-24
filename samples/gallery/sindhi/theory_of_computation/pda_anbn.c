#ضمن <stdio.h>
/* pushdown automata: accept a^n b^n (n >= 1) with a stack, reading a's then b's */
صحيح قبولي(ثابت حرف *لفظ) {
  حرف ٿهي[64]; صحيح چوٽي = 0, state = 0, index = 0;           /* state 0 reads a's, state 1 reads b's */
  لكل (; لفظ[index]; index++) {
    إذا (state == 0 && لفظ[index] == 'a') ٿهي[چوٽي++] = 'A';
    وإلا إذا (لفظ[index] == 'b' && چوٽي > 0 && ٿهي[چوٽي - 1] == 'A') { state = 1; چوٽي--; }
    وإلا أرجع 0;
  }
  أرجع state == 1 && چوٽي == 0;
}
صحيح مکيه(فراغ) { لکو("%d %d %d %d\n", قبولي("ab"), قبولي("aaabbb"), قبولي("aabbb"), قبولي("abab")); أرجع 0; }
