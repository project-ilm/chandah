#समावेश <stdio.h>
#समावेश <math.h>
/* linear algebra: the largest eigenvalue of a symmetric matrix by power iteration */
पूर्णांक मुख्य(व्योम) {
  द्विगुन matrix[3][3] = {{4, 1, 0}, {1, 3, 1}, {0, 1, 2}}, vector[3] = {1, 1, 1}, मान = 0;
  क्रम (पूर्णांक round = 0; round < 100; round++) {
    द्विगुन अग्र[3] = {0}, लंबाई = 0;
    क्रम (पूर्णांक row = 0; row < 3; row++) क्रम (पूर्णांक col = 0; col < 3; col++) अग्र[row] += matrix[row][col] * vector[col];
    क्रम (पूर्णांक row = 0; row < 3; row++) लंबाई += अग्र[row] * अग्र[row];
    लंबाई = वर्ग_मूल(लंबाई);
    मान = 0;
    क्रम (पूर्णांक row = 0; row < 3; row++) { मान += vector[row] * अग्र[row]; vector[row] = अग्र[row] / लंबाई; }
  }
  म_लिखो("%.4f\n", मान);
  वापस 0;
}
