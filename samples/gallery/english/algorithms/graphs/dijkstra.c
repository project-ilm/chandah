#include <stdio.h>
#include <limits.h>
/* Dijkstra's shortest paths from vertex 0 */
int main(void) {
  int weight[5][5] = {{0,10,0,30,100},{10,0,50,0,0},{0,50,0,20,10},{30,0,20,0,60},{100,0,10,60,0}};
  int distance[5], done[5] = {0};
  for (int vertex = 0; vertex < 5; vertex++) distance[vertex] = INT_MAX;
  distance[0] = 0;
  for (int round = 0; round < 5; round++) {
    int nearest = -1;
    for (int vertex = 0; vertex < 5; vertex++) if (!done[vertex] && (nearest < 0 || distance[vertex] < distance[nearest])) nearest = vertex;
    done[nearest] = 1;
    for (int next = 0; next < 5; next++)
      if (weight[nearest][next] && distance[nearest] + weight[nearest][next] < distance[next]) distance[next] = distance[nearest] + weight[nearest][next];
  }
  for (int vertex = 0; vertex < 5; vertex++) printf("%d ", distance[vertex]);
  printf("\n");
  return 0;
}
