#include <stdio.h>
/* quick sort, Lomuto partition */
void swap(int *first, int *second) { int temp = *first; *first = *second; *second = temp; }
int partition(int values[], int low, int high) {
  int pivot = values[high], index = low - 1;
  for (int scan = low; scan < high; scan++)
    if (values[scan] <= pivot) { index++; swap(&values[index], &values[scan]); }
  swap(&values[index + 1], &values[high]);
  return index + 1;
}
void quick_sort(int values[], int low, int high) {
  if (low < high) { int middle = partition(values, low, high); quick_sort(values, low, middle - 1); quick_sort(values, middle + 1, high); }
}
int main(void) {
  int values[] = {29, 3, 72, 14, 8, 55, 1, 40}, count = 8;
  quick_sort(values, 0, count - 1);
  for (int index = 0; index < count; index++) printf("%d ", values[index]);
  printf("\n");
  return 0;
}
