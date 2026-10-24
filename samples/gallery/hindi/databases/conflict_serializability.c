#समावेश <stdio.h>
/* transactions: test a schedule for conflict serializability through its precedence graph */
पूर्णांक graph[3][3], visited[3], active[3];
पूर्णांक cycle(पूर्णांक vertex) {
  visited[vertex] = active[vertex] = 1;
  क्रम (पूर्णांक अग्र = 0; अग्र < 3; अग्र++)
    अगर (graph[vertex][अग्र] && (active[अग्र] || (!visited[अग्र] && cycle(अग्र)))) वापस 1;
  active[vertex] = 0;
  वापस 0;
}
पूर्णांक मुख्य(व्योम) {
  /* the schedule: each step is transaction, read (0) or write (1), item */
  पूर्णांक schedule[6][3] = {{0, 0, 0}, {1, 1, 0}, {0, 1, 0}, {1, 0, 1}, {2, 1, 1}, {0, 0, 1}}, found = 0;
  क्रम (पूर्णांक first = 0; first < 6; first++)
    क्रम (पूर्णांक second = first + 1; second < 6; second++)
      अगर (schedule[first][0] != schedule[second][0] && schedule[first][2] == schedule[second][2] && (schedule[first][1] || schedule[second][1]))
        graph[schedule[first][0]][schedule[second][0]] = 1;
  क्रम (पूर्णांक vertex = 0; vertex < 3; vertex++) अगर (!visited[vertex] && cycle(vertex)) found = 1;
  म_लिखो("%s\n", found ? "not serializable" : "serializable");
  वापस 0;
}
