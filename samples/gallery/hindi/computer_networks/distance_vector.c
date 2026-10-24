#समावेश <stdio.h>
/* routing: distance-vector rounds (Bellman-Ford) until no table changes; 99 means unreachable */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक cost[4][4] = {{0, 1, 99, 7}, {1, 0, 2, 99}, {99, 2, 0, 1}, {7, 99, 1, 0}}, distance[4][4], rounds = 0, changed = 1;
  क्रम (पूर्णांक from = 0; from < 4; from++) क्रम (पूर्णांक to = 0; to < 4; to++) distance[from][to] = cost[from][to];
  जबतक (changed) {
    changed = 0; rounds++;
    क्रम (पूर्णांक from = 0; from < 4; from++)
      क्रम (पूर्णांक via = 0; via < 4; via++)
        क्रम (पूर्णांक to = 0; to < 4; to++)
          अगर (cost[from][via] < 99 && cost[from][via] + distance[via][to] < distance[from][to]) { distance[from][to] = cost[from][via] + distance[via][to]; changed = 1; }
  }
  म_लिखो("%d %d %d %d rounds %d\n", distance[0][0], distance[0][1], distance[0][2], distance[0][3], rounds);
  वापस 0;
}
