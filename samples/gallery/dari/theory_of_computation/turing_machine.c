#ضمن <stdio.h>
#ضمن <string.h>
/* a Turing machine that adds one to a binary number written on its tape */
صحيح اصلی(فراغ) {
  حرف نوار[16] = "_1011_";
  صحيح سر = 4, state = 0, گامها = 0;           /* state 0 carries, state 1 halts */
  طالما (state == 0) {
    إذا (نوار[سر] == '1') { نوار[سر] = '0'; سر--; }
    وإلا { نوار[سر] = '1'; state = 1; }
    گامها++;
  }
  چاپ_کن("%s %d\n", نوار, گامها);
  أرجع 0;
}
