#include <stdio.h>
/* binary search in a sorted array */
int binary_search(int values[], int count, int key) {
  int low = 0, high = count - 1;
  while (low <= high) {
    int middle = low + (high - low) / 2;
    if (values[middle] == key) return middle;
    if (values[middle] < key) low = middle + 1; else high = middle - 1;
  }
  return -1;
}
int main(void) {
  int values[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  printf("%d %d\n", binary_search(values, 10, 23), binary_search(values, 10, 7));
  return 0;
}
