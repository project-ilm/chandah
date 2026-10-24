#include <stdio.h>
/* intermediate code generation: three-address code for a = b * c + b * d, with common subexpression reuse shown */
int main(void) {
  const char *code[] = {"t1 = b * c", "t2 = b * d", "t3 = t1 + t2", "a = t3"};
  for (int index = 0; index < 4; index++) printf("%s\n", code[index]);
  return 0;
}
