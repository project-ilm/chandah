#include <stdio.h>
/* round-robin CPU scheduling, quantum 2: completion and waiting times */
int main(void) {
  int burst[] = {5, 3, 1, 2}, remaining[4], finish[4], time = 0, done = 0, quantum = 2;
  for (int job = 0; job < 4; job++) remaining[job] = burst[job];
  while (done < 4)
    for (int job = 0; job < 4; job++) {
      if (remaining[job] == 0) continue;
      int slice = remaining[job] < quantum ? remaining[job] : quantum;
      time += slice; remaining[job] -= slice;
      if (remaining[job] == 0) { finish[job] = time; done++; }
    }
  int waiting = 0;
  for (int job = 0; job < 4; job++) { printf("%d ", finish[job]); waiting += finish[job] - burst[job]; }
  printf("\naverage waiting %.2f\n", waiting / 4.0);
  return 0;
}
