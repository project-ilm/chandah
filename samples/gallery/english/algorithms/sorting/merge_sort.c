#include <stdio.h>
/* merge sort, top down */
void merge(int values[], int left, int middle, int right) {
  int temp[64], first = left, second = middle + 1, next = 0;
  while (first <= middle && second <= right) temp[next++] = values[first] <= values[second] ? values[first++] : values[second++];
  while (first <= middle) temp[next++] = values[first++];
  while (second <= right) temp[next++] = values[second++];
  for (int index = 0; index < next; index++) values[left + index] = temp[index];
}
void merge_sort(int values[], int left, int right) {
  if (left >= right) return;
  int middle = (left + right) / 2;
  merge_sort(values, left, middle); merge_sort(values, middle + 1, right); merge(values, left, middle, right);
}
int main(void) {
  int values[] = {38, 27, 43, 3, 9, 82, 10}, count = 7;
  merge_sort(values, 0, count - 1);
  for (int index = 0; index < count; index++) printf("%d ", values[index]);
  printf("\n");
  return 0;
}
