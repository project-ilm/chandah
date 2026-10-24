#ضمن <stdio.h>
#ضمن <stdint.h>
/* number representation: two's complement in eight bits, overflow, and fixed-point (Q4.4) multiplication */
صحيح اصلي(فراغ) {
  int8_t ارزښت = -5;
  صحيح مجموعه = 100 + 50;
  صحيح ډکېدنه = مجموعه > 127 || مجموعه < -128;
  صحيح لومړی = (صحيح)(2.5 * 16), دوهم = (صحيح)(1.75 * 16), حاصل_ضرب = (لومړی * دوهم) >> 4;
  چاپ_کړه("%02X %d %d %.4f\n", (uint8_t)ارزښت, (int8_t)مجموعه, ډکېدنه, حاصل_ضرب / 16.0);
  أرجع 0;
}
