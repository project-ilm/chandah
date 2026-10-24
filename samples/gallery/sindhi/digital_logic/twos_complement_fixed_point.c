#ضمن <stdio.h>
#ضمن <stdint.h>
/* number representation: two's complement in eight bits, overflow, and fixed-point (Q4.4) multiplication */
صحيح مکيه(فراغ) {
  int8_t قدر = -5;
  صحيح جوڙ = 100 + 50;
  صحيح حد_کان_مٿي = جوڙ > 127 || جوڙ < -128;
  صحيح پهريون = (صحيح)(2.5 * 16), ٻيو = (صحيح)(1.75 * 16), حاصل_ضرب = (پهريون * ٻيو) >> 4;
  لکو("%02X %d %d %.4f\n", (uint8_t)قدر, (int8_t)جوڙ, حد_کان_مٿي, حاصل_ضرب / 16.0);
  أرجع 0;
}
