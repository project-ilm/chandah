#ضمن <stdio.h>
/* control unit design: a microprogrammed sequencer; each microinstruction names its control signals and the next one */
ثابت حرف *سیګنالونه[] = {"PC->MAR", "MEM->MDR PC+1", "MDR->IR", "dispatch", "IR->MAR", "MEM->MDR", "MDR+ACC->ACC", "MDR->ACC"};
صحيح بل[] = {1, 2, 3, -1, 5, 6, 0, 0};
صحيح اصلي(فراغ) {
  صحيح پیل[2] = {4, 4}, پای[2] = {6, 7};   /* ADD and LOAD share the operand fetch, then differ */
  لكل (صحيح ډول = 0; ډول < 2; ډول++) {
    صحيح پته = 0;
    طالما (پته != -1) {
      چاپ_کړه("%s; ", سیګنالونه[پته]);
      پته = بل[پته];
    }
    لكل (پته = پیل[ډول]; پته != 6; پته = بل[پته]) چاپ_کړه("%s; ", سیګنالونه[پته]);
    چاپ_کړه("%s\n", سیګنالونه[پای[ډول]]);
  }
  أرجع 0;
}
