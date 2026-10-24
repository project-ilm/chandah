#شامل <stdio.h>
/* the Internet checksum (one's complement sum of 16-bit words) */
صحیح مین(خالی) {
  غیرعلامتی الفاظ[] = {0x4500, 0x0073, 0x0000, 0x4000, 0x4011, 0x0000, 0xC0A8, 0x0001, 0xC0A8, 0x00C7}, مجموع = 0;
  برائے (صحیح index = 0; index < 10; index++) مجموع += الفاظ[index];
  جب (مجموع >> 16) مجموع = (مجموع & 0xFFFF) + (مجموع >> 16);
  لکھو("%04X\n", ~مجموع & 0xFFFF);
  واپس 0;
}
