#ضمن <stdio.h>
/* pushdown automata: accept a^n b^n (n >= 1) with a stack, reading a's then b's */
صحيح میپذیرد(ثابت حرف *کلمه) {
  حرف پشته[64]; صحيح قله = 0, state = 0, index = 0;           /* state 0 reads a's, state 1 reads b's */
  لكل (; کلمه[index]; index++) {
    إذا (state == 0 && کلمه[index] == 'a') پشته[قله++] = 'A';
    وإلا إذا (کلمه[index] == 'b' && قله > 0 && پشته[قله - 1] == 'A') { state = 1; قله--; }
    وإلا أرجع 0;
  }
  أرجع state == 1 && قله == 0;
}
صحيح اصلی(فراغ) { چاپ_کن("%d %d %d %d\n", میپذیرد("ab"), میپذیرد("aaabbb"), میپذیرد("aabbb"), میپذیرد("abab")); أرجع 0; }
