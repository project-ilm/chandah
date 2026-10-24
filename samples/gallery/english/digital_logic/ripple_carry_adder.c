#include <stdio.h>
/* a four-bit ripple-carry adder built from full adders */
int main(void) {
  int first = 11, second = 6, carry = 0, sum = 0;
  for (int bit = 0; bit < 4; bit++) {
    int a = (first >> bit) & 1, b = (second >> bit) & 1;
    sum |= (a ^ b ^ carry) << bit;
    carry = (a & b) | (carry & (a ^ b));
  }
  printf("%d carry %d\n", sum, carry);
  return 0;
}
