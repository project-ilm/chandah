#समावेश <stdio.h>
/* CRC-32, the polynomial Ethernet uses, bit by bit */
अचिन्हित crc32(स्थिर अक्षर *text) {
  अचिन्हित crc = 0xFFFFFFFFu;
  क्रम (पूर्णांक index = 0; text[index]; index++) {
    crc ^= (अचिन्हित अक्षर)text[index];
    क्रम (पूर्णांक bit = 0; bit < 8; bit++) crc = (crc >> 1) ^ (0xEDB88320u & -(crc & 1));
  }
  वापस ~crc;
}
पूर्णांक मुख्य(व्योम) { म_लिखो("%08X\n", crc32("The quick brown fox jumps over the lazy dog")); वापस 0; }
