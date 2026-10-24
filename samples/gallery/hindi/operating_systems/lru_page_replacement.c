#समावेश <stdio.h>
/* least recently used page replacement with three frames: count the faults */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2}, frame[3] = {-1, -1, -1}, used[3] = {0}, faults = 0;
  क्रम (पूर्णांक समय = 0; समय < 13; समय++) {
    पूर्णांक hit = -1;
    क्रम (पूर्णांक slot = 0; slot < 3; slot++) अगर (frame[slot] == pages[समय]) hit = slot;
    अगर (hit < 0) {
      hit = 0;
      क्रम (पूर्णांक slot = 1; slot < 3; slot++) अगर (used[slot] < used[hit]) hit = slot;
      frame[hit] = pages[समय]; faults++;
    }
    used[hit] = समय + 1;
  }
  म_लिखो("%d\n", faults);
  वापस 0;
}
