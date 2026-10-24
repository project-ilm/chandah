#समावेश <stdio.h>
/* control unit design: a microprogrammed sequencer; each microinstruction names its control signals and the next one */
स्थिर अक्षर *signals[] = {"PC->MAR", "MEM->MDR PC+1", "MDR->IR", "dispatch", "IR->MAR", "MEM->MDR", "MDR+ACC->ACC", "MDR->ACC"};
पूर्णांक अग्र[] = {1, 2, 3, -1, 5, 6, 0, 0};
पूर्णांक मुख्य(व्योम) {
  पूर्णांक start[2] = {4, 4}, finish[2] = {6, 7};   /* ADD and LOAD share the operand fetch, then differ */
  क्रम (पूर्णांक kind = 0; kind < 2; kind++) {
    पूर्णांक address = 0;
    जबतक (address != -1) {
      म_लिखो("%s; ", signals[address]);
      address = अग्र[address];
    }
    क्रम (address = start[kind]; address != 6; address = अग्र[address]) म_लिखो("%s; ", signals[address]);
    म_लिखो("%s\n", signals[finish[kind]]);
  }
  वापस 0;
}
