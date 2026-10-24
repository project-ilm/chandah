#include <stdio.h>
/* instruction pipelining: a five-stage pipeline with forwarding stalls one cycle after each load whose result is used next */
int main(void) {
  int load[] = {1, 0, 1, 0, 0, 1, 0}, uses_previous[] = {0, 1, 0, 0, 1, 0, 1}, count = 7, stalls = 0;
  for (int index = 1; index < count; index++) if (load[index - 1] && uses_previous[index]) stalls++;
  printf("cycles %d stalls %d\n", 5 + (count - 1) + stalls, stalls);
  return 0;
}
