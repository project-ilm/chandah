#include <stdio.h>
#include <limits.h>
/* matrix chain multiplication order */
int main(void) {
  int size[] = {40, 20, 30, 10, 30}, count = 4, cost[8][8] = {{0}};
  for (int length = 2; length <= count; length++)
    for (int first = 1; first + length - 1 <= count; first++) {
      int last = first + length - 1;
      cost[first][last] = INT_MAX;
      for (int split = first; split < last; split++) {
        int total = cost[first][split] + cost[split + 1][last] + size[first - 1] * size[split] * size[last];
        if (total < cost[first][last]) cost[first][last] = total;
      }
    }
  printf("%d\n", cost[1][count]);
  return 0;
}
