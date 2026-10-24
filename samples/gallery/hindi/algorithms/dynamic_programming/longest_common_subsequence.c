#समावेश <stdio.h>
#समावेश <string.h>
/* longest common subsequence length */
पूर्णांक मुख्य(व्योम) {
  अक्षर first[] = "AGGTAB", second[] = "GXTXAYB";
  पूर्णांक rows = म_माप(first), cols = म_माप(second), table[16][16] = {{0}};
  क्रम (पूर्णांक row = 1; row <= rows; row++)
    क्रम (पूर्णांक col = 1; col <= cols; col++)
      table[row][col] = first[row - 1] == second[col - 1] ? table[row - 1][col - 1] + 1
                      : (table[row - 1][col] > table[row][col - 1] ? table[row - 1][col] : table[row][col - 1]);
  म_लिखो("%d\n", table[rows][cols]);
  वापस 0;
}
