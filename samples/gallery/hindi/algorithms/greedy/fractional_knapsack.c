#समावेश <stdio.h>
/* fractional knapsack: items already sorted by value per unit weight */
पूर्णांक मुख्य(व्योम) {
  द्विगुन मान[] = {60, 100, 120}, weight[] = {10, 20, 30}, capacity = 50, योग_2 = 0;
  क्रम (पूर्णांक item = 0; item < 3 && capacity > 0; item++) {
    द्विगुन taken = weight[item] < capacity ? weight[item] : capacity;
    योग_2 += मान[item] * taken / weight[item];
    capacity -= taken;
  }
  म_लिखो("%.2f\n", योग_2);
  वापस 0;
}
