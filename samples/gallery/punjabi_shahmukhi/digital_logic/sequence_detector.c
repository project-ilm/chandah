#ضمن <stdio.h>
/* sequential circuits: a Moore state machine that detects 101 in a bit stream, overlaps allowed */
صحيح مکھ(فراغ) {
  صحيح اگلا[4][2] = {{0, 1}, {2, 1}, {0, 3}, {2, 1}};      /* states: none, seen 1, seen 10, seen 101 */
  ثابت حرف *دھارا = "1101011010";
  صحيح state = 0;
  لكل (صحيح index = 0; دھارا[index]; index++) {
    state = اگلا[state][دھارا[index] - '0'];
    لکھو("%d", state == 3);
  }
  لکھو("\n");
  أرجع 0;
}
