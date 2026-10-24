#समावेश <stdio.h>
/* Banker's algorithm: find a safe sequence */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक allocation[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}}, maximum[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
  पूर्णांक available[3] = {3, 3, 2}, finished[5] = {0}, found = 0;
  जबतक (found < 5) {
    पूर्णांक progress = 0;
    क्रम (पूर्णांक job = 0; job < 5; job++) {
      अगर (finished[job]) जारी;
      पूर्णांक fits = 1;
      क्रम (पूर्णांक kind = 0; kind < 3; kind++) अगर (maximum[job][kind] - allocation[job][kind] > available[kind]) fits = 0;
      अगर (fits) { क्रम (पूर्णांक kind = 0; kind < 3; kind++) available[kind] += allocation[job][kind]; finished[job] = 1; found++; progress = 1; म_लिखो("P%d ", job); }
    }
    अगर (!progress) { म_लिखो("unsafe"); अवरोध; }
  }
  म_लिखो("\n");
  वापस 0;
}
