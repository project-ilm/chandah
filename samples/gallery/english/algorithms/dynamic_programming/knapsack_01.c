#include <stdio.h>
/* 0/1 knapsack, bottom up */
int main(void) {
  int value[] = {60, 100, 120}, weight[] = {10, 20, 30}, count = 3, capacity = 50, best[51] = {0};
  for (int item = 0; item < count; item++)
    for (int room = capacity; room >= weight[item]; room--)
      if (best[room - weight[item]] + value[item] > best[room]) best[room] = best[room - weight[item]] + value[item];
  printf("%d\n", best[capacity]);
  return 0;
}
