#ضمن <stdio.h>
/* sequential circuits: a Moore state machine that detects 101 in a bit stream, overlaps allowed */
صحيح اصلي(فراغ) {
  صحيح بل[4][2] = {{0, 1}, {2, 1}, {0, 3}, {2, 1}};      /* states: none, seen 1, seen 10, seen 101 */
  ثابت حرف *بهیر = "1101011010";
  صحيح state = 0;
  لكل (صحيح index = 0; بهیر[index]; index++) {
    state = بل[state][بهیر[index] - '0'];
    چاپ_کړه("%d", state == 3);
  }
  چاپ_کړه("\n");
  أرجع 0;
}
