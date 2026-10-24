#समावेश <stdio.h>
/* N queens: count the solutions for N = 6 */
पूर्णांक column[8], आकार = 6, solutions = 0;
पूर्णांक safe(पूर्णांक row, पूर्णांक col) {
  क्रम (पूर्णांक prior = 0; prior < row; prior++)
    अगर (column[prior] == col || column[prior] - col == prior - row || col - column[prior] == prior - row) वापस 0;
  वापस 1;
}
व्योम place(पूर्णांक row) {
  अगर (row == आकार) { solutions++; वापस; }
  क्रम (पूर्णांक col = 0; col < आकार; col++) अगर (safe(row, col)) { column[row] = col; place(row + 1); }
}
पूर्णांक मुख्य(व्योम) { place(0); म_लिखो("%d\n", solutions); वापस 0; }
