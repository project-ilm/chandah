#include <stdio.h>
/* structures, unions and sizeof */
struct point { int x, y; };
union number { int whole; char bytes[4]; };
int main(void) {
  struct point corner = {3, 4};
  union number value;
  value.whole = 0x01020304;
  printf("%d %d %d\n", corner.x * corner.x + corner.y * corner.y, (int)sizeof(struct point), value.bytes[0] == 4 || value.bytes[0] == 1);
  return 0;
}
