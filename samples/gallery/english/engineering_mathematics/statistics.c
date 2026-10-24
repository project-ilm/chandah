#include <stdio.h>
#include <math.h>
/* probability and statistics: mean, median, mode and standard deviation of sorted values */
int main(void) {
  int values[] = {2, 3, 3, 5, 7, 8, 8, 8, 9}, count = 9, mode = values[0], best = 0;
  double total = 0, spread = 0;
  for (int index = 0; index < count; index++) total += values[index];
  double mean = total / count;
  for (int index = 0; index < count; index++) spread += (values[index] - mean) * (values[index] - mean);
  for (int index = 0, run = 1; index < count; index++, run = (index < count && values[index] == values[index - 1]) ? run + 1 : 1)
    if (run > best) { best = run; mode = values[index]; }
  printf("mean %.2f median %d mode %d deviation %.2f\n", mean, values[count / 2], mode, sqrt(spread / count));
  return 0;
}
