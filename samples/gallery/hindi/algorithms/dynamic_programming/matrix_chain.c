#समावेश <stdio.h>
#समावेश <limits.h>
/* matrix chain multiplication order */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक आकार[] = {40, 20, 30, 10, 30}, count = 4, cost[8][8] = {{0}};
  क्रम (पूर्णांक लंबाई = 2; लंबाई <= count; लंबाई++)
    क्रम (पूर्णांक first = 1; first + लंबाई - 1 <= count; first++) {
      पूर्णांक last = first + लंबाई - 1;
      cost[first][last] = पूर्णांक_उच्च;
      क्रम (पूर्णांक split = first; split < last; split++) {
        पूर्णांक योग_2 = cost[first][split] + cost[split + 1][last] + आकार[first - 1] * आकार[split] * आकार[last];
        अगर (योग_2 < cost[first][last]) cost[first][last] = योग_2;
      }
    }
  म_लिखो("%d\n", cost[1][count]);
  वापस 0;
}
