#include <stdio.h>
/* calculus: integrate x*x from 0 to 3 by Simpson's rule */
double curve(double point) { return point * point; }
int main(void) {
  double low = 0, high = 3, width = (high - low) / 6, total = curve(low) + curve(high);
  for (int step = 1; step < 6; step++) total += (step % 2 ? 4 : 2) * curve(low + step * width);
  printf("%.4f\n", total * width / 3);
  return 0;
}
