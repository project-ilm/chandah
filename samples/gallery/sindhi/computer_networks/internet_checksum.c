#ضمن <stdio.h>
/* the Internet checksum (one's complement sum of 16-bit words) */
صحيح مکيه(فراغ) {
  بنانشان لفظن[] = {0x4500, 0x0073, 0x0000, 0x4000, 0x4011, 0x0000, 0xC0A8, 0x0001, 0xC0A8, 0x00C7}, جوڙ = 0;
  لكل (صحيح index = 0; index < 10; index++) جوڙ += لفظن[index];
  طالما (جوڙ >> 16) جوڙ = (جوڙ & 0xFFFF) + (جوڙ >> 16);
  لکو("%04X\n", ~جوڙ & 0xFFFF);
  أرجع 0;
}
