#ضمن <stdio.h>
/* the Internet checksum (one's complement sum of 16-bit words) */
صحيح اصلي(فراغ) {
  بینښه کلمې[] = {0x4500, 0x0073, 0x0000, 0x4000, 0x4011, 0x0000, 0xC0A8, 0x0001, 0xC0A8, 0x00C7}, مجموعه = 0;
  لكل (صحيح index = 0; index < 10; index++) مجموعه += کلمې[index];
  طالما (مجموعه >> 16) مجموعه = (مجموعه & 0xFFFF) + (مجموعه >> 16);
  چاپ_کړه("%04X\n", ~مجموعه & 0xFFFF);
  أرجع 0;
}
