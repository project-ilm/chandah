#समावेश <stdio.h>
/* graphs: maximum matching of students to courses by augmenting paths */
पूर्णांक wants[4][4] = {{1,1,0,0},{1,0,0,0},{0,1,1,0},{0,0,1,1}}, course_of[4], student_of[4], visited[4];
पूर्णांक assign(पूर्णांक student) {
  क्रम (पूर्णांक course = 0; course < 4; course++)
    अगर (wants[student][course] && !visited[course]) {
      visited[course] = 1;
      अगर (student_of[course] < 0 || assign(student_of[course])) { student_of[course] = student; course_of[student] = course; वापस 1; }
    }
  वापस 0;
}
पूर्णांक मुख्य(व्योम) {
  पूर्णांक योग_2 = 0;
  क्रम (पूर्णांक index = 0; index < 4; index++) student_of[index] = -1;
  क्रम (पूर्णांक student = 0; student < 4; student++) {
    क्रम (पूर्णांक index = 0; index < 4; index++) visited[index] = 0;
    योग_2 += assign(student);
  }
  क्रम (पूर्णांक student = 0; student < 4; student++) म_लिखो("%d-%d ", student, course_of[student]);
  म_लिखो("\nmatched %d\n", योग_2);
  वापस 0;
}
