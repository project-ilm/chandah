#समावेश <stdio.h>
/* an equi-join of two small relations by hashing the smaller one */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक student[4][2] = {{1, 81}, {2, 72}, {3, 95}, {4, 60}};          /* id, marks */
  पूर्णांक course[5][2] = {{3, 101}, {1, 102}, {3, 103}, {5, 104}, {2, 105}}; /* student id, course */
  पूर्णांक bucket[8] = {0};
  क्रम (पूर्णांक row = 0; row < 4; row++) bucket[student[row][0] % 8] = row + 1;
  क्रम (पूर्णांक row = 0; row < 5; row++) {
    पूर्णांक match = bucket[course[row][0] % 8];
    अगर (match && student[match - 1][0] == course[row][0]) म_लिखो("%d %d %d\n", course[row][0], student[match - 1][1], course[row][1]);
  }
  वापस 0;
}
