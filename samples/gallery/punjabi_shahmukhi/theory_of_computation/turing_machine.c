#ضمن <stdio.h>
#ضمن <string.h>
/* a Turing machine that adds one to a binary number written on its tape */
صحيح مکھ(فراغ) {
  حرف فیتا[16] = "_1011_";
  صحيح سر = 4, state = 0, قدماں = 0;           /* state 0 carries, state 1 halts */
  طالما (state == 0) {
    إذا (فیتا[سر] == '1') { فیتا[سر] = '0'; سر--; }
    وإلا { فیتا[سر] = '1'; state = 1; }
    قدماں++;
  }
  لکھو("%s %d\n", فیتا, قدماں);
  أرجع 0;
}
