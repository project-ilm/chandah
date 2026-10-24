#include <stdio.h>
#include <string.h>
/* number representation: the sign, exponent and fraction of an IEEE 754 single-precision number */
int main(void) {
  float number = -6.25f;
  unsigned bits;
  memcpy(&bits, &number, sizeof bits);
  printf("sign %u exponent %u fraction %06X\n", bits >> 31, ((bits >> 23) & 0xFF) - 127, bits & 0x7FFFFF);
  return 0;
}
