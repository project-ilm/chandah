#include <stdio.h>
/* binary min-heap as a priority queue */
int heap[32], size = 0;
void insert(int value) {
  int child = size++;
  heap[child] = value;
  while (child > 0 && heap[(child - 1) / 2] > heap[child]) { int parent = (child - 1) / 2, temp = heap[parent]; heap[parent] = heap[child]; heap[child] = temp; child = parent; }
}
int extract(void) {
  int least = heap[0], parent = 0;
  heap[0] = heap[--size];
  for (;;) {
    int smallest = parent, left = 2 * parent + 1, right = left + 1;
    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;
    if (smallest == parent) break;
    int temp = heap[parent]; heap[parent] = heap[smallest]; heap[smallest] = temp; parent = smallest;
  }
  return least;
}
int main(void) {
  int values[] = {9, 4, 7, 1, 8, 2};
  for (int index = 0; index < 6; index++) insert(values[index]);
  while (size) printf("%d ", extract());
  printf("\n");
  return 0;
}
