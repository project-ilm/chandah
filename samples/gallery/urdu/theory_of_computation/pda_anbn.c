#شامل <stdio.h>
/* pushdown automata: accept a^n b^n (n >= 1) with a stack, reading a's then b's */
صحیح قبول_کرتا(ثابت حرف *لفظ) {
  حرف انبار[64]; صحیح چوٹی = 0, state = 0, index = 0;           /* state 0 reads a's, state 1 reads b's */
  برائے (; لفظ[index]; index++) {
    اگر (state == 0 && لفظ[index] == 'a') انبار[چوٹی++] = 'A';
    ورنہ اگر (لفظ[index] == 'b' && چوٹی > 0 && انبار[چوٹی - 1] == 'A') { state = 1; چوٹی--; }
    ورنہ واپس 0;
  }
  واپس state == 1 && چوٹی == 0;
}
صحیح مین(خالی) { لکھو("%d %d %d %d\n", قبول_کرتا("ab"), قبول_کرتا("aaabbb"), قبول_کرتا("aabbb"), قبول_کرتا("abab")); واپس 0; }
