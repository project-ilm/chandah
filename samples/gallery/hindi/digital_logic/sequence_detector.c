#समावेश <stdio.h>
/* sequential circuits: a Moore state machine that detects 101 in a bit stream, overlaps allowed */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक अग्र[4][2] = {{0, 1}, {2, 1}, {0, 3}, {2, 1}};      /* states: none, seen 1, seen 10, seen 101 */
  स्थिर अक्षर *stream = "1101011010";
  पूर्णांक state = 0;
  क्रम (पूर्णांक index = 0; stream[index]; index++) {
    state = अग्र[state][stream[index] - '0'];
    म_लिखो("%d", state == 3);
  }
  म_लिखो("\n");
  वापस 0;
}
