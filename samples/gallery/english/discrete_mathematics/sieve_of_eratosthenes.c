#include <stdio.h>
/* primes below 60 */
int main(void) {
  int composite[60] = {0};
  for (int number = 2; number < 60; number++) {
    if (composite[number]) continue;
    printf("%d ", number);
    for (int multiple = number * number; multiple < 60; multiple += number) composite[multiple] = 1;
  }
  printf("\n");
  return 0;
}
