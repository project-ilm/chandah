#ضمن <stdio.h>
/* control unit design: a microprogrammed sequencer; each microinstruction names its control signals and the next one */
ثابت حرف *سیگنالها[] = {"PC->MAR", "MEM->MDR PC+1", "MDR->IR", "dispatch", "IR->MAR", "MEM->MDR", "MDR+ACC->ACC", "MDR->ACC"};
صحيح بعدی[] = {1, 2, 3, -1, 5, 6, 0, 0};
صحيح اصلی(فراغ) {
  صحيح شروع[2] = {4, 4}, پایان[2] = {6, 7};   /* ADD and LOAD share the operand fetch, then differ */
  لكل (صحيح نوع = 0; نوع < 2; نوع++) {
    صحيح آدرس = 0;
    طالما (آدرس != -1) {
      چاپ_کن("%s; ", سیگنالها[آدرس]);
      آدرس = بعدی[آدرس];
    }
    لكل (آدرس = شروع[نوع]; آدرس != 6; آدرس = بعدی[آدرس]) چاپ_کن("%s; ", سیگنالها[آدرس]);
    چاپ_کن("%s\n", سیگنالها[پایان[نوع]]);
  }
  أرجع 0;
}
