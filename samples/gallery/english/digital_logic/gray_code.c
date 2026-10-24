#include <stdio.h>
/* binary to Gray code and back */
int main(void) {
  for (int number = 0; number < 8; number++) {
    int gray = number ^ (number >> 1), back = gray;
    for (int shift = gray >> 1; shift; shift >>= 1) back ^= shift;
    printf("%d:%d:%d ", number, gray, back);
  }
  printf("\n");
  return 0;
}
