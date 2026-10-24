#include <stdio.h>
/* topological sort, Kahn's algorithm */
int main(void) {
  int edges[6][6] = {{0},{0},{0,0,0,1},{0,1},{1,1},{1,0,1}}, indegree[6] = {0}, queue[6], head = 0, tail = 0;
  for (int from = 0; from < 6; from++) for (int to = 0; to < 6; to++) indegree[to] += edges[from][to];
  for (int vertex = 0; vertex < 6; vertex++) if (!indegree[vertex]) queue[tail++] = vertex;
  while (head < tail) {
    int vertex = queue[head++];
    printf("%d ", vertex);
    for (int to = 0; to < 6; to++) if (edges[vertex][to] && --indegree[to] == 0) queue[tail++] = to;
  }
  printf("\n");
  return 0;
}
