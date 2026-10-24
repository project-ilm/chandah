#include <stdio.h>
/* towers of Hanoi */
int moves = 0;
void hanoi(int disks, char from, char to, char spare) {
  if (disks == 0) return;
  hanoi(disks - 1, from, spare, to);
  printf("%c>%c ", from, to); moves++;
  hanoi(disks - 1, spare, to, from);
}
int main(void) { hanoi(3, 'A', 'C', 'B'); printf("\nmoves %d\n", moves); return 0; }
