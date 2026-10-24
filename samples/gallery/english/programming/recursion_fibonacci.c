#include <stdio.h>
/* recursion and memoisation: Fibonacci numbers */
long memo[64];
long fibonacci(int number) { if (number < 2) return number; if (memo[number]) return memo[number]; return memo[number] = fibonacci(number - 1) + fibonacci(number - 2); }
int main(void) { for (int number = 0; number <= 10; number++) printf("%ld ", fibonacci(number)); printf("\n%ld\n", fibonacci(50)); return 0; }
