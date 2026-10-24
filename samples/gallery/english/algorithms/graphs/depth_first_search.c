#include <stdio.h>
/* depth-first search, recursive */
int graph[6][6] = {{0,1,1,0,0,0},{1,0,0,1,1,0},{1,0,0,0,1,0},{0,1,0,0,1,1},{0,1,1,1,0,1},{0,0,0,1,1,0}}, visited[6];
void visit(int vertex) {
  visited[vertex] = 1;
  printf("%d ", vertex);
  for (int next = 0; next < 6; next++) if (graph[vertex][next] && !visited[next]) visit(next);
}
int main(void) { visit(0); printf("\n"); return 0; }
