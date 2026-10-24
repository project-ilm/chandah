#समावेश <stdio.h>
/* linear algebra: solve a system of three equations by Gaussian elimination, and its determinant */
पूर्णांक मुख्य(व्योम) {
  द्विगुन matrix[3][4] = {{2, 1, -1, 8}, {-3, -1, 2, -11}, {-2, 1, 2, -3}}, परिणाम[3], determinant = 1;
  क्रम (पूर्णांक pivot = 0; pivot < 3; pivot++) {
    determinant *= matrix[pivot][pivot];
    क्रम (पूर्णांक row = pivot + 1; row < 3; row++) {
      द्विगुन factor = matrix[row][pivot] / matrix[pivot][pivot];
      क्रम (पूर्णांक col = pivot; col < 4; col++) matrix[row][col] -= factor * matrix[pivot][col];
    }
  }
  क्रम (पूर्णांक row = 2; row >= 0; row--) {
    द्विगुन योग_2 = matrix[row][3];
    क्रम (पूर्णांक col = row + 1; col < 3; col++) योग_2 -= matrix[row][col] * परिणाम[col];
    परिणाम[row] = योग_2 / matrix[row][row];
  }
  म_लिखो("%.2f %.2f %.2f\ndeterminant %.2f\n", परिणाम[0], परिणाम[1], परिणाम[2], determinant);
  वापस 0;
}
