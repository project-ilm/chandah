#समावेश <stdio.h>
/* pointers and arrays: reverse in place, pointer arithmetic */
व्योम reverse(पूर्णांक *start, पूर्णांक *end) { जबतक (start < end) { पूर्णांक अस्थायी = *start; *start++ = *end; *end-- = अस्थायी; } }
पूर्णांक मुख्य(व्योम) {
  पूर्णांक values[] = {1, 2, 3, 4, 5, 6}, *pointer = values;
  reverse(values, values + 5);
  क्रम (पूर्णांक index = 0; index < 6; index++) म_लिखो("%d ", *(pointer + index));
  म_लिखो("\n%d\n", (पूर्णांक)(&values[5] - &values[0]));
  वापस 0;
}
