#include <stdio.h>
#include <string.h>
/* a Turing machine that adds one to a binary number written on its tape */
int main(void) {
  char tape[16] = "_1011_";
  int head = 4, state = 0, steps = 0;           /* state 0 carries, state 1 halts */
  while (state == 0) {
    if (tape[head] == '1') { tape[head] = '0'; head--; }
    else { tape[head] = '1'; state = 1; }
    steps++;
  }
  printf("%s %d\n", tape, steps);
  return 0;
}
