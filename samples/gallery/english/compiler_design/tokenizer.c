#include <stdio.h>
#include <ctype.h>
/* a hand-written lexer: identifiers, numbers and operators */
int main(void) {
  char source[] = "total = count1 + 42 * rate;";
  int index = 0, tokens = 0;
  while (source[index]) {
    if (isspace(source[index])) { index++; continue; }
    int start = index;
    if (isalpha(source[index])) { while (isalnum(source[index])) index++; printf("ID "); }
    else if (isdigit(source[index])) { while (isdigit(source[index])) index++; printf("NUM "); }
    else { index++; printf("OP "); }
    tokens++;
    (void)start;
  }
  printf("\n%d\n", tokens);
  return 0;
}
