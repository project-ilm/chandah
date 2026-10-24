#समावेश <stdio.h>
/* Kruskal's minimum spanning tree with union-find; edges sorted by weight */
पूर्णांक parent[6];
पूर्णांक find(पूर्णांक vertex) { वापस parent[vertex] == vertex ? vertex : (parent[vertex] = find(parent[vertex])); }
पूर्णांक मुख्य(व्योम) {
  पूर्णांक edge[9][3] = {{0,1,1},{2,3,2},{0,2,3},{1,2,4},{3,4,5},{1,3,6},{4,5,7},{2,5,8},{0,5,9}}, योग_2 = 0;
  क्रम (पूर्णांक vertex = 0; vertex < 6; vertex++) parent[vertex] = vertex;
  क्रम (पूर्णांक index = 0; index < 9; index++) {
    पूर्णांक from = find(edge[index][0]), to = find(edge[index][1]);
    अगर (from != to) { parent[from] = to; योग_2 += edge[index][2]; म_लिखो("%d-%d ", edge[index][0], edge[index][1]); }
  }
  म_लिखो("\ntotal %d\n", योग_2);
  वापस 0;
}
