#समावेश <stdio.h>
/* combinatorics: binary strings with no two adjacent ones (a recurrence), and Catalan numbers, by table */
पूर्णांक मुख्य(व्योम) {
  दीर्घ strings[16] = {1, 2}, catalan[16] = {1};
  क्रम (पूर्णांक लंबाई = 2; लंबाई < 16; लंबाई++) strings[लंबाई] = strings[लंबाई - 1] + strings[लंबाई - 2];
  क्रम (पूर्णांक आकार = 1; आकार < 16; आकार++)
    क्रम (पूर्णांक वाम = 0; वाम < आकार; वाम++) catalan[आकार] += catalan[वाम] * catalan[आकार - 1 - वाम];
  म_लिखो("%ld %ld\n", strings[10], catalan[10]);
  वापस 0;
}
