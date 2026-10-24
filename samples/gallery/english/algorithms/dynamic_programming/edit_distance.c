#include <stdio.h>
#include <string.h>
/* edit distance (Levenshtein) */
int smallest(int first, int second, int third) { int least = first < second ? first : second; return least < third ? least : third; }
int main(void) {
  char source[] = "kitten", target[] = "sitting";
  int rows = strlen(source), cols = strlen(target), cost[16][16];
  for (int row = 0; row <= rows; row++) cost[row][0] = row;
  for (int col = 0; col <= cols; col++) cost[0][col] = col;
  for (int row = 1; row <= rows; row++)
    for (int col = 1; col <= cols; col++)
      cost[row][col] = smallest(cost[row - 1][col] + 1, cost[row][col - 1] + 1, cost[row - 1][col - 1] + (source[row - 1] != target[col - 1]));
  printf("%d\n", cost[rows][cols]);
  return 0;
}
