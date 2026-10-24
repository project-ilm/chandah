#include <stdio.h>
/* pointers and arrays: reverse in place, pointer arithmetic */
void reverse(int *start, int *end) { while (start < end) { int temp = *start; *start++ = *end; *end-- = temp; } }
int main(void) {
  int values[] = {1, 2, 3, 4, 5, 6}, *pointer = values;
  reverse(values, values + 5);
  for (int index = 0; index < 6; index++) printf("%d ", *(pointer + index));
  printf("\n%d\n", (int)(&values[5] - &values[0]));
  return 0;
}
