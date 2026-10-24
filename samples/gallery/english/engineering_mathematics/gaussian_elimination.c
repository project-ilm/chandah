#include <stdio.h>
/* linear algebra: solve a system of three equations by Gaussian elimination, and its determinant */
int main(void) {
  double matrix[3][4] = {{2, 1, -1, 8}, {-3, -1, 2, -11}, {-2, 1, 2, -3}}, result[3], determinant = 1;
  for (int pivot = 0; pivot < 3; pivot++) {
    determinant *= matrix[pivot][pivot];
    for (int row = pivot + 1; row < 3; row++) {
      double factor = matrix[row][pivot] / matrix[pivot][pivot];
      for (int col = pivot; col < 4; col++) matrix[row][col] -= factor * matrix[pivot][col];
    }
  }
  for (int row = 2; row >= 0; row--) {
    double total = matrix[row][3];
    for (int col = row + 1; col < 3; col++) total -= matrix[row][col] * result[col];
    result[row] = total / matrix[row][row];
  }
  printf("%.2f %.2f %.2f\ndeterminant %.2f\n", result[0], result[1], result[2], determinant);
  return 0;
}
