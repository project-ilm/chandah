#include <stdio.h>
/* activity selection: activities sorted by finish time */
int main(void) {
  int start[] = {1, 3, 0, 5, 8, 5}, finish[] = {2, 4, 6, 7, 9, 9}, count = 6, last = 0, total = 1;
  printf("0 ");
  for (int next = 1; next < count; next++)
    if (start[next] >= finish[last]) { printf("%d ", next); last = next; total++; }
  printf("\ntotal %d\n", total);
  return 0;
}
