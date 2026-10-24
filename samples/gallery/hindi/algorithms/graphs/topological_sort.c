#समावेश <stdio.h>
/* topological sort, Kahn's algorithm */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक edges[6][6] = {{0},{0},{0,0,0,1},{0,1},{1,1},{1,0,1}}, indegree[6] = {0}, queue[6], शीर्ष = 0, पुच्छ = 0;
  क्रम (पूर्णांक from = 0; from < 6; from++) क्रम (पूर्णांक to = 0; to < 6; to++) indegree[to] += edges[from][to];
  क्रम (पूर्णांक vertex = 0; vertex < 6; vertex++) अगर (!indegree[vertex]) queue[पुच्छ++] = vertex;
  जबतक (शीर्ष < पुच्छ) {
    पूर्णांक vertex = queue[शीर्ष++];
    म_लिखो("%d ", vertex);
    क्रम (पूर्णांक to = 0; to < 6; to++) अगर (edges[vertex][to] && --indegree[to] == 0) queue[पुच्छ++] = to;
  }
  म_लिखो("\n");
  वापस 0;
}
