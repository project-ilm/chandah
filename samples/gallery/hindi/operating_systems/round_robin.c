#समावेश <stdio.h>
/* round-robin CPU scheduling, quantum 2: completion and waiting times */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक burst[] = {5, 3, 1, 2}, remaining[4], finish[4], समय = 0, done = 0, quantum = 2;
  क्रम (पूर्णांक job = 0; job < 4; job++) remaining[job] = burst[job];
  जबतक (done < 4)
    क्रम (पूर्णांक job = 0; job < 4; job++) {
      अगर (remaining[job] == 0) जारी;
      पूर्णांक slice = remaining[job] < quantum ? remaining[job] : quantum;
      समय += slice; remaining[job] -= slice;
      अगर (remaining[job] == 0) { finish[job] = समय; done++; }
    }
  पूर्णांक waiting = 0;
  क्रम (पूर्णांक job = 0; job < 4; job++) { म_लिखो("%d ", finish[job]); waiting += finish[job] - burst[job]; }
  म_लिखो("\naverage waiting %.2f\n", waiting / 4.0);
  वापस 0;
}
