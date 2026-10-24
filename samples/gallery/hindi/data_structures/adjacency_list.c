#समावेश <stdio.h>
/* graphs: adjacency lists kept in arrays, and breadth-first distances from vertex 0 */
पूर्णांक शीर्ष[6], target[16], अग्र[16], edges = 0;
व्योम add(पूर्णांक from, पूर्णांक to) { target[edges] = to; अग्र[edges] = शीर्ष[from]; शीर्ष[from] = edges++; }
पूर्णांक मुख्य(व्योम) {
  क्रम (पूर्णांक vertex = 0; vertex < 6; vertex++) शीर्ष[vertex] = -1;
  पूर्णांक pairs[7][2] = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};
  क्रम (पूर्णांक index = 0; index < 7; index++) { add(pairs[index][0], pairs[index][1]); add(pairs[index][1], pairs[index][0]); }
  पूर्णांक distance[6], queue[6], first = 0, last = 0;
  क्रम (पूर्णांक vertex = 0; vertex < 6; vertex++) distance[vertex] = -1;
  distance[0] = 0; queue[last++] = 0;
  जबतक (first < last) {
    पूर्णांक vertex = queue[first++];
    क्रम (पूर्णांक edge = शीर्ष[vertex]; edge >= 0; edge = अग्र[edge])
      अगर (distance[target[edge]] < 0) { distance[target[edge]] = distance[vertex] + 1; queue[last++] = target[edge]; }
  }
  क्रम (पूर्णांक vertex = 0; vertex < 6; vertex++) म_लिखो("%d ", distance[vertex]);
  म_लिखो("\n");
  वापस 0;
}
