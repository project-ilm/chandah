#समावेश <stdio.h>
#समावेश <string.h>
/* edit distance (Levenshtein) */
पूर्णांक smallest(पूर्णांक first, पूर्णांक second, पूर्णांक third) { पूर्णांक least = first < second ? first : second; वापस least < third ? least : third; }
पूर्णांक मुख्य(व्योम) {
  अक्षर source[] = "kitten", target[] = "sitting";
  पूर्णांक rows = म_माप(source), cols = म_माप(target), cost[16][16];
  क्रम (पूर्णांक row = 0; row <= rows; row++) cost[row][0] = row;
  क्रम (पूर्णांक col = 0; col <= cols; col++) cost[0][col] = col;
  क्रम (पूर्णांक row = 1; row <= rows; row++)
    क्रम (पूर्णांक col = 1; col <= cols; col++)
      cost[row][col] = smallest(cost[row - 1][col] + 1, cost[row][col - 1] + 1, cost[row - 1][col - 1] + (source[row - 1] != target[col - 1]));
  म_लिखो("%d\n", cost[rows][cols]);
  वापस 0;
}
