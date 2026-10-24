#ضمن <stdio.h>
/* control unit design: a microprogrammed sequencer; each microinstruction names its control signals and the next one */
ثابت حرف *اشارے[] = {"PC->MAR", "MEM->MDR PC+1", "MDR->IR", "dispatch", "IR->MAR", "MEM->MDR", "MDR+ACC->ACC", "MDR->ACC"};
صحيح اگلا[] = {1, 2, 3, -1, 5, 6, 0, 0};
صحيح مکھ(فراغ) {
  صحيح شروع[2] = {4, 4}, انت[2] = {6, 7};   /* ADD and LOAD share the operand fetch, then differ */
  لكل (صحيح قسم = 0; قسم < 2; قسم++) {
    صحيح پتہ = 0;
    طالما (پتہ != -1) {
      لکھو("%s; ", اشارے[پتہ]);
      پتہ = اگلا[پتہ];
    }
    لكل (پتہ = شروع[قسم]; پتہ != 6; پتہ = اگلا[پتہ]) لکھو("%s; ", اشارے[پتہ]);
    لکھو("%s\n", اشارے[انت[قسم]]);
  }
  أرجع 0;
}
