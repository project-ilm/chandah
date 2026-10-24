#समावेश <stdio.h>
/* normal forms: the closure of a set of attributes under functional dependencies; attributes A..F are bits */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक वाम[] = {1 | 2, 2 | 4, 8, 16}, दक्षिण[] = {4, 8, 16, 32}, closure = 1 | 2, changed = 1;   /* AB->C, BC->D, D->E, E->F */
  जबतक (changed) {
    changed = 0;
    क्रम (पूर्णांक index = 0; index < 4; index++)
      अगर ((closure & वाम[index]) == वाम[index] && (closure | दक्षिण[index]) != closure) { closure |= दक्षिण[index]; changed = 1; }
  }
  क्रम (पूर्णांक bit = 0; bit < 6; bit++) अगर (closure & (1 << bit)) म_लिखो("%c", 'A' + bit);
  म_लिखो("\n");
  वापस 0;
}
