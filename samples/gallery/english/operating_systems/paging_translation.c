#include <stdio.h>
/* memory management: translate virtual addresses with a page table, page size 1024 */
int main(void) {
  int table[8] = {5, 2, -1, 7, 1, -1, 3, 0}, addresses[] = {100, 2048, 3100, 7000, 5000};
  for (int index = 0; index < 5; index++) {
    int page = addresses[index] / 1024, offset = addresses[index] % 1024;
    if (table[page] < 0) printf("fault ");
    else printf("%d ", table[page] * 1024 + offset);
  }
  printf("\n");
  return 0;
}
