#समावेश <stdio.h>
#समावेश <limits.h>
/* Dijkstra's shortest paths from vertex 0 */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक weight[5][5] = {{0,10,0,30,100},{10,0,50,0,0},{0,50,0,20,10},{30,0,20,0,60},{100,0,10,60,0}};
  पूर्णांक distance[5], done[5] = {0};
  क्रम (पूर्णांक vertex = 0; vertex < 5; vertex++) distance[vertex] = पूर्णांक_उच्च;
  distance[0] = 0;
  क्रम (पूर्णांक round = 0; round < 5; round++) {
    पूर्णांक nearest = -1;
    क्रम (पूर्णांक vertex = 0; vertex < 5; vertex++) अगर (!done[vertex] && (nearest < 0 || distance[vertex] < distance[nearest])) nearest = vertex;
    done[nearest] = 1;
    क्रम (पूर्णांक अग्र = 0; अग्र < 5; अग्र++)
      अगर (weight[nearest][अग्र] && distance[nearest] + weight[nearest][अग्र] < distance[अग्र]) distance[अग्र] = distance[nearest] + weight[nearest][अग्र];
  }
  क्रम (पूर्णांक vertex = 0; vertex < 5; vertex++) म_लिखो("%d ", distance[vertex]);
  म_लिखो("\n");
  वापस 0;
}
