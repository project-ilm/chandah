#include <stdio.h>
/* a DFA over binary strings that accepts multiples of three */
int accepts(const char *word) {
  int state = 0;
  for (int index = 0; word[index]; index++) state = (state * 2 + (word[index] - '0')) % 3;
  return state == 0;
}
int main(void) { printf("%d %d %d %d\n", accepts("110"), accepts("111"), accepts("1001"), accepts("0")); return 0; }
