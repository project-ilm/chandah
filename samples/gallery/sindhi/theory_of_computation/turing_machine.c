#ضمن <stdio.h>
#ضمن <string.h>
/* a Turing machine that adds one to a binary number written on its tape */
صحيح مکيه(فراغ) {
  حرف پٽي[16] = "_1011_";
  صحيح سر = 4, state = 0, قدمن = 0;           /* state 0 carries, state 1 halts */
  طالما (state == 0) {
    إذا (پٽي[سر] == '1') { پٽي[سر] = '0'; سر--; }
    وإلا { پٽي[سر] = '1'; state = 1; }
    قدمن++;
  }
  لکو("%s %d\n", پٽي, قدمن);
  أرجع 0;
}
