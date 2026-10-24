#include <stdio.h>
/* transactions: test a schedule for conflict serializability through its precedence graph */
int graph[3][3], visited[3], active[3];
int cycle(int vertex) {
  visited[vertex] = active[vertex] = 1;
  for (int next = 0; next < 3; next++)
    if (graph[vertex][next] && (active[next] || (!visited[next] && cycle(next)))) return 1;
  active[vertex] = 0;
  return 0;
}
int main(void) {
  /* the schedule: each step is transaction, read (0) or write (1), item */
  int schedule[6][3] = {{0, 0, 0}, {1, 1, 0}, {0, 1, 0}, {1, 0, 1}, {2, 1, 1}, {0, 0, 1}}, found = 0;
  for (int first = 0; first < 6; first++)
    for (int second = first + 1; second < 6; second++)
      if (schedule[first][0] != schedule[second][0] && schedule[first][2] == schedule[second][2] && (schedule[first][1] || schedule[second][1]))
        graph[schedule[first][0]][schedule[second][0]] = 1;
  for (int vertex = 0; vertex < 3; vertex++) if (!visited[vertex] && cycle(vertex)) found = 1;
  printf("%s\n", found ? "not serializable" : "serializable");
  return 0;
}
