#ضمن <stdio.h>
#ضمن <stdint.h>
/* number representation: two's complement in eight bits, overflow, and fixed-point (Q4.4) multiplication */
صحيح مکھ(فراغ) {
  int8_t قیمت = -5;
  صحيح جوڑ = 100 + 50;
  صحيح حد_توں_ودھ = جوڑ > 127 || جوڑ < -128;
  صحيح پہلا = (صحيح)(2.5 * 16), دوجا = (صحيح)(1.75 * 16), ضرب_حاصل = (پہلا * دوجا) >> 4;
  لکھو("%02X %d %d %.4f\n", (uint8_t)قیمت, (int8_t)جوڑ, حد_توں_ودھ, ضرب_حاصل / 16.0);
  أرجع 0;
}
