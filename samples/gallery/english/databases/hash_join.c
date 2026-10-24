#include <stdio.h>
/* an equi-join of two small relations by hashing the smaller one */
int main(void) {
  int student[4][2] = {{1, 81}, {2, 72}, {3, 95}, {4, 60}};          /* id, marks */
  int course[5][2] = {{3, 101}, {1, 102}, {3, 103}, {5, 104}, {2, 105}}; /* student id, course */
  int bucket[8] = {0};
  for (int row = 0; row < 4; row++) bucket[student[row][0] % 8] = row + 1;
  for (int row = 0; row < 5; row++) {
    int match = bucket[course[row][0] % 8];
    if (match && student[match - 1][0] == course[row][0]) printf("%d %d %d\n", course[row][0], student[match - 1][1], course[row][1]);
  }
  return 0;
}
