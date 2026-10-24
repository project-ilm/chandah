#include <stdio.h>
/* IPv4 and CIDR: the network, broadcast address and host count of 192.168.10.77/26 */
int main(void) {
  unsigned address = (192u << 24) | (168 << 16) | (10 << 8) | 77, prefix = 26, mask = prefix ? ~0u << (32 - prefix) : 0;
  unsigned network = address & mask, broadcast = network | ~mask;
  printf("%u.%u.%u.%u %u.%u.%u.%u %u\n", network >> 24, (network >> 16) & 255, (network >> 8) & 255, network & 255,
         broadcast >> 24, (broadcast >> 16) & 255, (broadcast >> 8) & 255, broadcast & 255, (1u << (32 - prefix)) - 2);
  return 0;
}
