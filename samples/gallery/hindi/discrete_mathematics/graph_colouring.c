#समावेश <stdio.h>
/* graphs: greedy colouring; each vertex takes the smallest colour no neighbour has */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक graph[6][6] = {{0,1,1,0,0,1},{1,0,1,1,0,0},{1,1,0,1,1,0},{0,1,1,0,1,0},{0,0,1,1,0,1},{1,0,0,0,1,0}};
  पूर्णांक colour[6], count = 0;
  क्रम (पूर्णांक vertex = 0; vertex < 6; vertex++) {
    पूर्णांक used[6] = {0};
    क्रम (पूर्णांक अग्र = 0; अग्र < vertex; अग्र++) अगर (graph[vertex][अग्र]) used[colour[अग्र]] = 1;
    colour[vertex] = 0;
    जबतक (used[colour[vertex]]) colour[vertex]++;
    अगर (colour[vertex] + 1 > count) count = colour[vertex] + 1;
    म_लिखो("%d ", colour[vertex]);
  }
  म_लिखो("\ncolours %d\n", count);
  वापस 0;
}
