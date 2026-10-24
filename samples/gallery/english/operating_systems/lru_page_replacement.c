#include <stdio.h>
/* least recently used page replacement with three frames: count the faults */
int main(void) {
  int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}, frame[3] = {-1, -1, -1}, used[3] = {0}, faults = 0;
  for (int time = 0; time < 13; time++) {
    int hit = -1;
    for (int slot = 0; slot < 3; slot++) if (frame[slot] == pages[time]) hit = slot;
    if (hit < 0) {
      hit = 0;
      for (int slot = 1; slot < 3; slot++) if (used[slot] < used[hit]) hit = slot;
      frame[hit] = pages[time]; faults++;
    }
    used[hit] = time + 1;
  }
  printf("%d\n", faults);
  return 0;
}
