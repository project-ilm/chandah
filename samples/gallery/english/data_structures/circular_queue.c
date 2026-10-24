#include <stdio.h>
/* circular queue of size 4 */
int queue[4], head = 0, count = 0;
int enqueue(int value) { if (count == 4) return 0; queue[(head + count++) % 4] = value; return 1; }
int dequeue(void) { int value = queue[head]; head = (head + 1) % 4; count--; return value; }
int main(void) {
  for (int value = 1; value <= 5; value++) printf("%d ", enqueue(value * 10));
  int first = dequeue(), second = dequeue();
  printf("| %d %d | ", first, second);
  enqueue(60); enqueue(70);
  while (count) printf("%d ", dequeue());
  printf("\n");
  return 0;
}
