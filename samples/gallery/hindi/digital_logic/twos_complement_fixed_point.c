#समावेश <stdio.h>
#समावेश <stdint.h>
/* number representation: two's complement in eight bits, overflow, and fixed-point (Q4.4) multiplication */
पूर्णांक मुख्य(व्योम) {
  int8_t मान = -5;
  पूर्णांक योग = 100 + 50;
  पूर्णांक overflow = योग > 127 || योग < -128;
  पूर्णांक first = (पूर्णांक)(2.5 * 16), second = (पूर्णांक)(1.75 * 16), product = (first * second) >> 4;
  म_लिखो("%02X %d %d %.4f\n", (uint8_t)मान, (int8_t)योग, overflow, product / 16.0);
  वापस 0;
}
