#include <stdio.h>
/* CRC-32, the polynomial Ethernet uses, bit by bit */
unsigned crc32(const char *text) {
  unsigned crc = 0xFFFFFFFFu;
  for (int index = 0; text[index]; index++) {
    crc ^= (unsigned char)text[index];
    for (int bit = 0; bit < 8; bit++) crc = (crc >> 1) ^ (0xEDB88320u & -(crc & 1));
  }
  return ~crc;
}
int main(void) { printf("%08X\n", crc32("The quick brown fox jumps over the lazy dog")); return 0; }
