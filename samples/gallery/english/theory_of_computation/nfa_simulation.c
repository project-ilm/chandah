#include <stdio.h>
/* an NFA, simulated on sets of states, accepting binary strings whose second-last symbol is 1 */
int accepts(const char *word) {
  int states = 1;                                /* bit k set means state k is active */
  for (int index = 0; word[index]; index++) {
    int next = 1;                                /* state 0 loops on both symbols */
    if (word[index] == '1' && (states & 1)) next |= 2;
    if (states & 2) next |= 4;
    states = next;
  }
  return (states & 4) != 0;
}
int main(void) { printf("%d %d %d %d\n", accepts("10"), accepts("0110"), accepts("011"), accepts("1")); return 0; }
