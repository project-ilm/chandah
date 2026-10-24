#include <stdio.h>
/* normal forms: the closure of a set of attributes under functional dependencies; attributes A..F are bits */
int main(void) {
  int left[] = {1 | 2, 2 | 4, 8, 16}, right[] = {4, 8, 16, 32}, closure = 1 | 2, changed = 1;   /* AB->C, BC->D, D->E, E->F */
  while (changed) {
    changed = 0;
    for (int index = 0; index < 4; index++)
      if ((closure & left[index]) == left[index] && (closure | right[index]) != closure) { closure |= right[index]; changed = 1; }
  }
  for (int bit = 0; bit < 6; bit++) if (closure & (1 << bit)) printf("%c", 'A' + bit);
  printf("\n");
  return 0;
}
