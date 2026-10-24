#समावेश <stdio.h>
/* merge sort, top down */
व्योम merge(पूर्णांक values[], पूर्णांक वाम, पूर्णांक middle, पूर्णांक दक्षिण) {
  पूर्णांक अस्थायी[64], first = वाम, second = middle + 1, अग्र = 0;
  जबतक (first <= middle && second <= दक्षिण) अस्थायी[अग्र++] = values[first] <= values[second] ? values[first++] : values[second++];
  जबतक (first <= middle) अस्थायी[अग्र++] = values[first++];
  जबतक (second <= दक्षिण) अस्थायी[अग्र++] = values[second++];
  क्रम (पूर्णांक index = 0; index < अग्र; index++) values[वाम + index] = अस्थायी[index];
}
व्योम merge_sort(पूर्णांक values[], पूर्णांक वाम, पूर्णांक दक्षिण) {
  अगर (वाम >= दक्षिण) वापस;
  पूर्णांक middle = (वाम + दक्षिण) / 2;
  merge_sort(values, वाम, middle); merge_sort(values, middle + 1, दक्षिण); merge(values, वाम, middle, दक्षिण);
}
पूर्णांक मुख्य(व्योम) {
  पूर्णांक values[] = {38, 27, 43, 3, 9, 82, 10}, count = 7;
  merge_sort(values, 0, count - 1);
  क्रम (पूर्णांक index = 0; index < count; index++) म_लिखो("%d ", values[index]);
  म_लिखो("\n");
  वापस 0;
}
