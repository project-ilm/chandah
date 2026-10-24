#समावेश <stdio.h>
/* an NFA, simulated on sets of states, accepting binary strings whose second-last symbol is 1 */
पूर्णांक accepts(स्थिर अक्षर *word) {
  पूर्णांक states = 1;                                /* bit k set means state k is active */
  क्रम (पूर्णांक index = 0; word[index]; index++) {
    पूर्णांक अग्र = 1;                                /* state 0 loops on both symbols */
    अगर (word[index] == '1' && (states & 1)) अग्र |= 2;
    अगर (states & 2) अग्र |= 4;
    states = अग्र;
  }
  वापस (states & 4) != 0;
}
पूर्णांक मुख्य(व्योम) { म_लिखो("%d %d %d %d\n", accepts("10"), accepts("0110"), accepts("011"), accepts("1")); वापस 0; }
