#समावेश <stdio.h>
/* Floyd-Warshall all-pairs shortest paths; 999 means no edge */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक distance[4][4] = {{0,5,999,10},{999,0,3,999},{999,999,0,1},{999,999,999,0}};
  क्रम (पूर्णांक via = 0; via < 4; via++)
    क्रम (पूर्णांक from = 0; from < 4; from++)
      क्रम (पूर्णांक to = 0; to < 4; to++)
        अगर (distance[from][via] + distance[via][to] < distance[from][to]) distance[from][to] = distance[from][via] + distance[via][to];
  क्रम (पूर्णांक from = 0; from < 4; from++) { क्रम (पूर्णांक to = 0; to < 4; to++) म_लिखो("%d ", distance[from][to]); म_लिखो("\n"); }
  वापस 0;
}
