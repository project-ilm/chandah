#समावेश <stdio.h>
/* linear algebra: LU decomposition (Doolittle) of a 3 by 3 matrix */
पूर्णांक मुख्य(व्योम) {
  द्विगुन matrix[3][3] = {{2, -1, -2}, {-4, 6, 3}, {-4, -2, 8}}, lower[3][3] = {{0}}, upper[3][3] = {{0}};
  क्रम (पूर्णांक row = 0; row < 3; row++) {
    क्रम (पूर्णांक col = row; col < 3; col++) {
      द्विगुन योग = 0;
      क्रम (पूर्णांक index = 0; index < row; index++) योग += lower[row][index] * upper[index][col];
      upper[row][col] = matrix[row][col] - योग;
    }
    lower[row][row] = 1;
    क्रम (पूर्णांक below = row + 1; below < 3; below++) {
      द्विगुन योग = 0;
      क्रम (पूर्णांक index = 0; index < row; index++) योग += lower[below][index] * upper[index][row];
      lower[below][row] = (matrix[below][row] - योग) / upper[row][row];
    }
  }
  क्रम (पूर्णांक row = 0; row < 3; row++) म_लिखो("%g %g %g | %g %g %g\n", lower[row][0], lower[row][1], lower[row][2], upper[row][0], upper[row][1], upper[row][2]);
  वापस 0;
}
