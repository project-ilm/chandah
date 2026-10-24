#include <stdio.h>
/* Banker's algorithm: find a safe sequence */
int main(void) {
  int allocation[5][3] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}}, maximum[5][3] = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
  int available[3] = {3, 3, 2}, finished[5] = {0}, found = 0;
  while (found < 5) {
    int progress = 0;
    for (int job = 0; job < 5; job++) {
      if (finished[job]) continue;
      int fits = 1;
      for (int kind = 0; kind < 3; kind++) if (maximum[job][kind] - allocation[job][kind] > available[kind]) fits = 0;
      if (fits) { for (int kind = 0; kind < 3; kind++) available[kind] += allocation[job][kind]; finished[job] = 1; found++; progress = 1; printf("P%d ", job); }
    }
    if (!progress) { printf("unsafe"); break; }
  }
  printf("\n");
  return 0;
}
