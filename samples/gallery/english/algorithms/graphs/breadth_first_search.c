#include <stdio.h>
/* breadth-first search on an adjacency matrix */
int main(void) {
  int graph[6][6] = {{0,1,1,0,0,0},{1,0,0,1,1,0},{1,0,0,0,1,0},{0,1,0,0,1,1},{0,1,1,1,0,1},{0,0,0,1,1,0}};
  int queue[6], visited[6] = {0}, head = 0, tail = 0;
  queue[tail++] = 0; visited[0] = 1;
  while (head < tail) {
    int vertex = queue[head++];
    printf("%d ", vertex);
    for (int next = 0; next < 6; next++)
      if (graph[vertex][next] && !visited[next]) { visited[next] = 1; queue[tail++] = next; }
  }
  printf("\n");
  return 0;
}
