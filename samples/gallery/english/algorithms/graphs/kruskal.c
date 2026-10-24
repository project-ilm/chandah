#include <stdio.h>
/* Kruskal's minimum spanning tree with union-find; edges sorted by weight */
int parent[6];
int find(int vertex) { return parent[vertex] == vertex ? vertex : (parent[vertex] = find(parent[vertex])); }
int main(void) {
  int edge[9][3] = {{0,1,1},{2,3,2},{0,2,3},{1,2,4},{3,4,5},{1,3,6},{4,5,7},{2,5,8},{0,5,9}}, total = 0;
  for (int vertex = 0; vertex < 6; vertex++) parent[vertex] = vertex;
  for (int index = 0; index < 9; index++) {
    int from = find(edge[index][0]), to = find(edge[index][1]);
    if (from != to) { parent[from] = to; total += edge[index][2]; printf("%d-%d ", edge[index][0], edge[index][1]); }
  }
  printf("\ntotal %d\n", total);
  return 0;
}
