#include <stdio.h>
/* heap sort with a max heap */
void sift_down(int values[], int size, int root) {
  int largest = root, left = 2 * root + 1, right = 2 * root + 2;
  if (left < size && values[left] > values[largest]) largest = left;
  if (right < size && values[right] > values[largest]) largest = right;
  if (largest != root) { int temp = values[root]; values[root] = values[largest]; values[largest] = temp; sift_down(values, size, largest); }
}
int main(void) {
  int values[] = {12, 11, 13, 5, 6, 7}, count = 6;
  for (int root = count / 2 - 1; root >= 0; root--) sift_down(values, count, root);
  for (int last = count - 1; last > 0; last--) {
    int temp = values[0]; values[0] = values[last]; values[last] = temp;
    sift_down(values, last, 0);
  }
  for (int index = 0; index < count; index++) printf("%d ", values[index]);
  printf("\n");
  return 0;
}
