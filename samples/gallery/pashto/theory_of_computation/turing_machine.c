#ضمن <stdio.h>
#ضمن <string.h>
/* a Turing machine that adds one to a binary number written on its tape */
صحيح اصلي(فراغ) {
  حرف فیته[16] = "_1011_";
  صحيح سر = 4, state = 0, ګامونه = 0;           /* state 0 carries, state 1 halts */
  طالما (state == 0) {
    إذا (فیته[سر] == '1') { فیته[سر] = '0'; سر--; }
    وإلا { فیته[سر] = '1'; state = 1; }
    ګامونه++;
  }
  چاپ_کړه("%s %d\n", فیته, ګامونه);
  أرجع 0;
}
