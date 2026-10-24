#समावेश <stdio.h>
/* activity selection: activities sorted by finish time */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक start[] = {1, 3, 0, 5, 8, 5}, finish[] = {2, 4, 6, 7, 9, 9}, count = 6, last = 0, योग_2 = 1;
  म_लिखो("0 ");
  क्रम (पूर्णांक अग्र = 1; अग्र < count; अग्र++)
    अगर (start[अग्र] >= finish[last]) { म_लिखो("%d ", अग्र); last = अग्र; योग_2++; }
  म_लिखो("\ntotal %d\n", योग_2);
  वापस 0;
}
