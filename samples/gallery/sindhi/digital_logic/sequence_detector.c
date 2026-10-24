#ضمن <stdio.h>
/* sequential circuits: a Moore state machine that detects 101 in a bit stream, overlaps allowed */
صحيح مکيه(فراغ) {
  صحيح ايندڙ[4][2] = {{0, 1}, {2, 1}, {0, 3}, {2, 1}};      /* states: none, seen 1, seen 10, seen 101 */
  ثابت حرف *وهڪرو = "1101011010";
  صحيح state = 0;
  لكل (صحيح index = 0; وهڪرو[index]; index++) {
    state = ايندڙ[state][وهڪرو[index] - '0'];
    لکو("%d", state == 3);
  }
  لکو("\n");
  أرجع 0;
}
