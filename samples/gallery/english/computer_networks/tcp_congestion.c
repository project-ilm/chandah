#include <stdio.h>
/* TCP congestion control: slow start, congestion avoidance, and a timeout at round 8 */
int main(void) {
  int window = 1, threshold = 16;
  for (int round = 1; round <= 12; round++) {
    printf("%d ", window);
    if (round == 8) { threshold = window / 2; window = 1; }
    else if (window < threshold) window *= 2;
    else window += 1;
  }
  printf("\n");
  return 0;
}
