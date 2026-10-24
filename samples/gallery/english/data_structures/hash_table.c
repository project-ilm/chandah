#include <stdio.h>
/* hash table with linear probing */
int keys[11], used[11];
int slot_of(int key) { int slot = key % 11; while (used[slot] && keys[slot] != key) slot = (slot + 1) % 11; return slot; }
void insert(int key) { int slot = slot_of(key); keys[slot] = key; used[slot] = 1; }
int contains(int key) { return used[slot_of(key)]; }
int main(void) {
  int values[] = {22, 1, 13, 11, 24, 33, 18, 42, 31};
  for (int index = 0; index < 9; index++) insert(values[index]);
  for (int slot = 0; slot < 11; slot++) printf("%d ", used[slot] ? keys[slot] : -1);
  printf("\n%d %d\n", contains(42), contains(5));
  return 0;
}
