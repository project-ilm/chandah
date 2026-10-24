#include <stdio.h>
/* the Internet checksum (one's complement sum of 16-bit words) */
int main(void) {
  unsigned words[] = {0x4500, 0x0073, 0x0000, 0x4000, 0x4011, 0x0000, 0xC0A8, 0x0001, 0xC0A8, 0x00C7}, sum = 0;
  for (int index = 0; index < 10; index++) sum += words[index];
  while (sum >> 16) sum = (sum & 0xFFFF) + (sum >> 16);
  printf("%04X\n", ~sum & 0xFFFF);
  return 0;
}
