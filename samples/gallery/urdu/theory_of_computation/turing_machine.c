#شامل <stdio.h>
#شامل <string.h>
/* a Turing machine that adds one to a binary number written on its tape */
صحیح مین(خالی) {
  حرف فیتہ[16] = "_1011_";
  صحیح سر = 4, state = 0, اقدام = 0;           /* state 0 carries, state 1 halts */
  جب (state == 0) {
    اگر (فیتہ[سر] == '1') { فیتہ[سر] = '0'; سر--; }
    ورنہ { فیتہ[سر] = '1'; state = 1; }
    اقدام++;
  }
  لکھو("%s %d\n", فیتہ, اقدام);
  واپس 0;
}
