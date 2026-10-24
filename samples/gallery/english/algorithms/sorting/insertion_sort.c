#include <stdio.h>
/* insertion sort */
int main(void) {
  int values[] = {31, 41, 59, 26, 41, 58}, count = 6;
  for (int next = 1; next < count; next++) {
    int key = values[next], index = next - 1;
    while (index >= 0 && values[index] > key) { values[index + 1] = values[index]; index--; }
    values[index + 1] = key;
  }
  for (int index = 0; index < count; index++) printf("%d ", values[index]);
  printf("\n");
  return 0;
}
