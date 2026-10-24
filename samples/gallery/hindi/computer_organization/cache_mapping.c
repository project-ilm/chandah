#समावेश <stdio.h>
/* memory hierarchy: a direct-mapped cache of four lines, block size 4 words; count hits and misses */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक addresses[] = {0, 4, 8, 0, 16, 4, 32, 0, 8, 48}, tags[4], used[4] = {0}, hits = 0, misses = 0;
  क्रम (पूर्णांक index = 0; index < 10; index++) {
    पूर्णांक block = addresses[index] / 4, line = block % 4, tag = block / 4;
    अगर (used[line] && tags[line] == tag) hits++;
    अन्यथा { misses++; used[line] = 1; tags[line] = tag; }
  }
  म_लिखो("hits %d misses %d\n", hits, misses);
  वापस 0;
}
