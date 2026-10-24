#समावेश <stdio.h>
/* the Internet checksum (one's complement sum of 16-bit words) */
पूर्णांक मुख्य(व्योम) {
  अचिन्हित words[] = {0x4500, 0x0073, 0x0000, 0x4000, 0x4011, 0x0000, 0xC0A8, 0x0001, 0xC0A8, 0x00C7}, योग = 0;
  क्रम (पूर्णांक index = 0; index < 10; index++) योग += words[index];
  जबतक (योग >> 16) योग = (योग & 0xFFFF) + (योग >> 16);
  म_लिखो("%04X\n", ~योग & 0xFFFF);
  वापस 0;
}
