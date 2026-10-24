#include <stdio.h>
/* probability: Bayes' theorem for a test with known sensitivity and false-positive rate */
int main(void) {
  double prior = 0.01, sensitivity = 0.95, false_positive = 0.05;
  double evidence = sensitivity * prior + false_positive * (1 - prior);
  printf("%.4f\n", sensitivity * prior / evidence);
  return 0;
}
