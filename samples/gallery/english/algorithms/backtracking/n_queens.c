#include <stdio.h>
/* N queens: count the solutions for N = 6 */
int column[8], size = 6, solutions = 0;
int safe(int row, int col) {
  for (int prior = 0; prior < row; prior++)
    if (column[prior] == col || column[prior] - col == prior - row || col - column[prior] == prior - row) return 0;
  return 1;
}
void place(int row) {
  if (row == size) { solutions++; return; }
  for (int col = 0; col < size; col++) if (safe(row, col)) { column[row] = col; place(row + 1); }
}
int main(void) { place(0); printf("%d\n", solutions); return 0; }
