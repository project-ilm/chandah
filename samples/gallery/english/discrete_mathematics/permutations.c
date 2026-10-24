#include <stdio.h>
/* all permutations of 1..3, by swapping */
int values[] = {1, 2, 3}, total = 0;
void permute(int start) {
  if (start == 3) { printf("%d%d%d ", values[0], values[1], values[2]); total++; return; }
  for (int index = start; index < 3; index++) {
    int temp = values[start]; values[start] = values[index]; values[index] = temp;
    permute(start + 1);
    temp = values[start]; values[start] = values[index]; values[index] = temp;
  }
}
int main(void) { permute(0); printf("\n%d\n", total); return 0; }
