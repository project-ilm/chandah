#समावेश <stdio.h>
/* insertion sort */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक values[] = {31, 41, 59, 26, 41, 58}, count = 6;
  क्रम (पूर्णांक अग्र = 1; अग्र < count; अग्र++) {
    पूर्णांक कुंजी = values[अग्र], index = अग्र - 1;
    जबतक (index >= 0 && values[index] > कुंजी) { values[index + 1] = values[index]; index--; }
    values[index + 1] = कुंजी;
  }
  क्रम (पूर्णांक index = 0; index < count; index++) म_लिखो("%d ", values[index]);
  म_लिखो("\n");
  वापस 0;
}
