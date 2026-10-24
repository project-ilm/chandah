#समावेश <stdio.h>
/* 0/1 knapsack, bottom up */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक मान[] = {60, 100, 120}, weight[] = {10, 20, 30}, count = 3, capacity = 50, best[51] = {0};
  क्रम (पूर्णांक item = 0; item < count; item++)
    क्रम (पूर्णांक room = capacity; room >= weight[item]; room--)
      अगर (best[room - weight[item]] + मान[item] > best[room]) best[room] = best[room - weight[item]] + मान[item];
  म_लिखो("%d\n", best[capacity]);
  वापस 0;
}
