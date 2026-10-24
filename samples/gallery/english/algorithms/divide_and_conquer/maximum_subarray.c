#include <stdio.h>
/* maximum subarray sum, divide and conquer */
int largest(int first, int second) { return first > second ? first : second; }
int crossing(int values[], int low, int middle, int high) {
  int sum = 0, left = -100000, right = -100000;
  for (int index = middle; index >= low; index--) { sum += values[index]; left = largest(left, sum); }
  sum = 0;
  for (int index = middle + 1; index <= high; index++) { sum += values[index]; right = largest(right, sum); }
  return left + right;
}
int best(int values[], int low, int high) {
  if (low == high) return values[low];
  int middle = (low + high) / 2;
  return largest(largest(best(values, low, middle), best(values, middle + 1, high)), crossing(values, low, middle, high));
}
int main(void) { int values[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; printf("%d\n", best(values, 0, 8)); return 0; }
