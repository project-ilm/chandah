#include <stdio.h>
/* fractional knapsack: items already sorted by value per unit weight */
int main(void) {
  double value[] = {60, 100, 120}, weight[] = {10, 20, 30}, capacity = 50, total = 0;
  for (int item = 0; item < 3 && capacity > 0; item++) {
    double taken = weight[item] < capacity ? weight[item] : capacity;
    total += value[item] * taken / weight[item];
    capacity -= taken;
  }
  printf("%.2f\n", total);
  return 0;
}
