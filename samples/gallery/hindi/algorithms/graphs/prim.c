#समावेश <stdio.h>
/* minimum spanning trees: Prim's algorithm on a weight matrix (0 means no edge) */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक weight[5][5] = {{0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0}};
  पूर्णांक cost[5], parent[5], done[5] = {0}, योग_2 = 0;
  क्रम (पूर्णांक vertex = 0; vertex < 5; vertex++) { cost[vertex] = 1000; parent[vertex] = -1; }
  cost[0] = 0;
  क्रम (पूर्णांक round = 0; round < 5; round++) {
    पूर्णांक nearest = -1;
    क्रम (पूर्णांक vertex = 0; vertex < 5; vertex++) अगर (!done[vertex] && (nearest < 0 || cost[vertex] < cost[nearest])) nearest = vertex;
    done[nearest] = 1; योग_2 += cost[nearest];
    अगर (parent[nearest] >= 0) म_लिखो("%d-%d ", parent[nearest], nearest);
    क्रम (पूर्णांक vertex = 0; vertex < 5; vertex++)
      अगर (weight[nearest][vertex] && !done[vertex] && weight[nearest][vertex] < cost[vertex]) { cost[vertex] = weight[nearest][vertex]; parent[vertex] = nearest; }
  }
  म_लिखो("\ntotal %d\n", योग_2);
  वापस 0;
}
