#समावेश <stdio.h>
/* all permutations of 1..3, by swapping */
पूर्णांक values[] = {1, 2, 3}, योग_2 = 0;
व्योम permute(पूर्णांक start) {
  अगर (start == 3) { म_लिखो("%d%d%d ", values[0], values[1], values[2]); योग_2++; वापस; }
  क्रम (पूर्णांक index = start; index < 3; index++) {
    पूर्णांक अस्थायी = values[start]; values[start] = values[index]; values[index] = अस्थायी;
    permute(start + 1);
    अस्थायी = values[start]; values[start] = values[index]; values[index] = अस्थायी;
  }
}
पूर्णांक मुख्य(व्योम) { permute(0); म_लिखो("\n%d\n", योग_2); वापस 0; }
