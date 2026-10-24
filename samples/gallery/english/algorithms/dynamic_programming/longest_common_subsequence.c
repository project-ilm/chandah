#include <stdio.h>
#include <string.h>
/* longest common subsequence length */
int main(void) {
  char first[] = "AGGTAB", second[] = "GXTXAYB";
  int rows = strlen(first), cols = strlen(second), table[16][16] = {{0}};
  for (int row = 1; row <= rows; row++)
    for (int col = 1; col <= cols; col++)
      table[row][col] = first[row - 1] == second[col - 1] ? table[row - 1][col - 1] + 1
                      : (table[row - 1][col] > table[row][col - 1] ? table[row - 1][col] : table[row][col - 1]);
  printf("%d\n", table[rows][cols]);
  return 0;
}
