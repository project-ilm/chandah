#ضمن <stdio.h>
/* sequential circuits: a Moore state machine that detects 101 in a bit stream, overlaps allowed */
صحيح اصلی(فراغ) {
  صحيح بعدی[4][2] = {{0, 1}, {2, 1}, {0, 3}, {2, 1}};      /* states: none, seen 1, seen 10, seen 101 */
  ثابت حرف *جریان = "1101011010";
  صحيح state = 0;
  لكل (صحيح index = 0; جریان[index]; index++) {
    state = بعدی[state][جریان[index] - '0'];
    چاپ_کن("%d", state == 3);
  }
  چاپ_کن("\n");
  أرجع 0;
}
