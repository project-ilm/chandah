#include <stdio.h>
/* Floyd-Warshall all-pairs shortest paths; 999 means no edge */
int main(void) {
  int distance[4][4] = {{0,5,999,10},{999,0,3,999},{999,999,0,1},{999,999,999,0}};
  for (int via = 0; via < 4; via++)
    for (int from = 0; from < 4; from++)
      for (int to = 0; to < 4; to++)
        if (distance[from][via] + distance[via][to] < distance[from][to]) distance[from][to] = distance[from][via] + distance[via][to];
  for (int from = 0; from < 4; from++) { for (int to = 0; to < 4; to++) printf("%d ", distance[from][to]); printf("\n"); }
  return 0;
}
