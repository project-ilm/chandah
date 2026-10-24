#ضمن <stdio.h>
/* control unit design: a microprogrammed sequencer; each microinstruction names its control signals and the next one */
ثابت حرف *سگنل[] = {"PC->MAR", "MEM->MDR PC+1", "MDR->IR", "dispatch", "IR->MAR", "MEM->MDR", "MDR+ACC->ACC", "MDR->ACC"};
صحيح ايندڙ[] = {1, 2, 3, -1, 5, 6, 0, 0};
صحيح مکيه(فراغ) {
  صحيح شروعات[2] = {4, 4}, پڄاڻي[2] = {6, 7};   /* ADD and LOAD share the operand fetch, then differ */
  لكل (صحيح قسم = 0; قسم < 2; قسم++) {
    صحيح پتو = 0;
    طالما (پتو != -1) {
      لکو("%s; ", سگنل[پتو]);
      پتو = ايندڙ[پتو];
    }
    لكل (پتو = شروعات[قسم]; پتو != 6; پتو = ايندڙ[پتو]) لکو("%s; ", سگنل[پتو]);
    لکو("%s\n", سگنل[پڄاڻي[قسم]]);
  }
  أرجع 0;
}
