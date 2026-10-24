#شامل <stdio.h>
/* control unit design: a microprogrammed sequencer; each microinstruction names its control signals and the next one */
ثابت حرف *اشارات[] = {"PC->MAR", "MEM->MDR PC+1", "MDR->IR", "dispatch", "IR->MAR", "MEM->MDR", "MDR+ACC->ACC", "MDR->ACC"};
صحیح اگلا[] = {1, 2, 3, -1, 5, 6, 0, 0};
صحیح مین(خالی) {
  صحیح آغاز[2] = {4, 4}, اختتام[2] = {6, 7};   /* ADD and LOAD share the operand fetch, then differ */
  برائے (صحیح قسم = 0; قسم < 2; قسم++) {
    صحیح پتہ = 0;
    جب (پتہ != -1) {
      لکھو("%s; ", اشارات[پتہ]);
      پتہ = اگلا[پتہ];
    }
    برائے (پتہ = آغاز[قسم]; پتہ != 6; پتہ = اگلا[پتہ]) لکھو("%s; ", اشارات[پتہ]);
    لکھو("%s\n", اشارات[اختتام[قسم]]);
  }
  واپس 0;
}
