#include <stdio.h>
/* Euclid's algorithm */
int gcd(int first, int second) { return second == 0 ? first : gcd(second, first % second); }
int main(void) { int first = 84, second = 36; printf("%d %d\n", gcd(first, second), first / gcd(first, second) * second); return 0; }
