#समावेश <stdio.h>
/* local optimisation: value numbering finds common subexpressions in a basic block */
पूर्णांक मुख्य(व्योम) {
  स्थिर अक्षर *names[] = {"a", "b", "c", "d", "t1", "t2", "t3"};
  पूर्णांक code[4][4] = {{4, 0, '+', 1}, {5, 0, '+', 1}, {6, 4, '*', 2}, {3, 5, '*', 2}};   /* t1 = a + b; t2 = a + b; ... */
  पूर्णांक number[7] = {0, 1, 2, 3, 4, 5, 6}, table[8][4], count = 0;
  क्रम (पूर्णांक index = 0; index < 4; index++) {
    पूर्णांक वाम = number[code[index][1]], दक्षिण = number[code[index][3]], found = -1;
    क्रम (पूर्णांक entry = 0; entry < count; entry++)
      अगर (table[entry][0] == वाम && table[entry][1] == code[index][2] && table[entry][2] == दक्षिण) found = table[entry][3];
    अगर (found >= 0) { number[code[index][0]] = found; म_लिखो("%s = %s\n", names[code[index][0]], names[found]); }
    अन्यथा {
      table[count][0] = वाम; table[count][1] = code[index][2]; table[count][2] = दक्षिण; table[count++][3] = code[index][0];
      number[code[index][0]] = code[index][0];
      म_लिखो("%s = %s %c %s\n", names[code[index][0]], names[वाम], code[index][2], names[दक्षिण]);
    }
  }
  वापस 0;
}
