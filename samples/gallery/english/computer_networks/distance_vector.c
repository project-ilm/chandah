#include <stdio.h>
/* routing: distance-vector rounds (Bellman-Ford) until no table changes; 99 means unreachable */
int main(void) {
  int cost[4][4] = {{0, 1, 99, 7}, {1, 0, 2, 99}, {99, 2, 0, 1}, {7, 99, 1, 0}}, distance[4][4], rounds = 0, changed = 1;
  for (int from = 0; from < 4; from++) for (int to = 0; to < 4; to++) distance[from][to] = cost[from][to];
  while (changed) {
    changed = 0; rounds++;
    for (int from = 0; from < 4; from++)
      for (int via = 0; via < 4; via++)
        for (int to = 0; to < 4; to++)
          if (cost[from][via] < 99 && cost[from][via] + distance[via][to] < distance[from][to]) { distance[from][to] = cost[from][via] + distance[via][to]; changed = 1; }
  }
  printf("%d %d %d %d rounds %d\n", distance[0][0], distance[0][1], distance[0][2], distance[0][3], rounds);
  return 0;
}
