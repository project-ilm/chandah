#include <stdio.h>
/* memory hierarchy: a direct-mapped cache of four lines, block size 4 words; count hits and misses */
int main(void) {
  int addresses[] = {0, 4, 8, 0, 16, 4, 32, 0, 8, 48}, tags[4], used[4] = {0}, hits = 0, misses = 0;
  for (int index = 0; index < 10; index++) {
    int block = addresses[index] / 4, line = block % 4, tag = block / 4;
    if (used[line] && tags[line] == tag) hits++;
    else { misses++; used[line] = 1; tags[line] = tag; }
  }
  printf("hits %d misses %d\n", hits, misses);
  return 0;
}
