#ضمن <stdio.h>
#ضمن <stdint.h>
/* number representation: two's complement in eight bits, overflow, and fixed-point (Q4.4) multiplication */
صحيح اصلی(فراغ) {
  int8_t مقدار = -5;
  صحيح جمع = 100 + 50;
  صحيح سرریز = جمع > 127 || جمع < -128;
  صحيح اولی = (صحيح)(2.5 * 16), دومی = (صحيح)(1.75 * 16), حاصلضرب = (اولی * دومی) >> 4;
  چاپ_کن("%02X %d %d %.4f\n", (uint8_t)مقدار, (int8_t)جمع, سرریز, حاصلضرب / 16.0);
  أرجع 0;
}
