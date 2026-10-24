#شامل <stdio.h>
#شامل <stdint.h>
/* number representation: two's complement in eight bits, overflow, and fixed-point (Q4.4) multiplication */
صحیح مین(خالی) {
  int8_t قدر = -5;
  صحیح مجموع = 100 + 50;
  صحیح حد_سے_تجاوز = مجموع > 127 || مجموع < -128;
  صحیح پہلا = (صحیح)(2.5 * 16), دوسرا = (صحیح)(1.75 * 16), حاصل_ضرب = (پہلا * دوسرا) >> 4;
  لکھو("%02X %d %d %.4f\n", (uint8_t)قدر, (int8_t)مجموع, حد_سے_تجاوز, حاصل_ضرب / 16.0);
  واپس 0;
}
