#समावेश <stdio.h>
/* normal forms: every candidate key of R(A,B,C,D,E) under A->B, B->C, CD->E, E->A (attributes are bits) */
पूर्णांक वाम[4] = {1, 2, 4 | 8, 16}, दक्षिण[4] = {2, 4, 16, 1};
पूर्णांक closure(पूर्णांक attributes) {
  क्रम (पूर्णांक changed = 1; changed; ) {
    changed = 0;
    क्रम (पूर्णांक index = 0; index < 4; index++)
      अगर ((attributes & वाम[index]) == वाम[index] && (attributes | दक्षिण[index]) != attributes) { attributes |= दक्षिण[index]; changed = 1; }
  }
  वापस attributes;
}
पूर्णांक मुख्य(व्योम) {
  पूर्णांक keys[32], count = 0;
  क्रम (पूर्णांक set = 1; set < 32; set++) {
    अगर (closure(set) != 31) जारी;
    पूर्णांक minimal = 1;
    क्रम (पूर्णांक index = 0; index < count; index++) अगर ((keys[index] & set) == keys[index]) minimal = 0;
    अगर (!minimal) जारी;
    keys[count++] = set;
    क्रम (पूर्णांक bit = 0; bit < 5; bit++) अगर (set >> bit & 1) अक्षर_दो('A' + bit);
    अक्षर_दो(' ');
  }
  म_लिखो("\n");
  वापस 0;
}
