#समावेश <stdio.h>
/* relational algebra: selection, projection and natural join over two small relations */
पूर्णांक student[4][2] = {{1, 81}, {2, 72}, {3, 95}, {4, 60}};              /* (id, marks) */
पूर्णांक course[5][2] = {{3, 101}, {1, 102}, {3, 103}, {5, 104}, {2, 105}};  /* (id, course) */
पूर्णांक मुख्य(व्योम) {
  म_लिखो("select marks > 70:");
  क्रम (पूर्णांक row = 0; row < 4; row++) अगर (student[row][1] > 70) म_लिखो(" (%d,%d)", student[row][0], student[row][1]);
  म_लिखो("\nproject course ids:");
  क्रम (पूर्णांक row = 0; row < 5; row++) {
    पूर्णांक seen = 0;
    क्रम (पूर्णांक prior = 0; prior < row; prior++) अगर (course[prior][0] == course[row][0]) seen = 1;
    अगर (!seen) म_लिखो(" %d", course[row][0]);
  }
  म_लिखो("\njoin on id:");
  क्रम (पूर्णांक first = 0; first < 4; first++)
    क्रम (पूर्णांक second = 0; second < 5; second++)
      अगर (student[first][0] == course[second][0]) म_लिखो(" (%d,%d,%d)", student[first][0], student[first][1], course[second][1]);
  म_लिखो("\n");
  वापस 0;
}
