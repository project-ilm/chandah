#ضمن <stdio.h>
/* the Internet checksum (one's complement sum of 16-bit words) */
صحيح مکھ(فراغ) {
  بنانشانی لفظاں[] = {0x4500, 0x0073, 0x0000, 0x4000, 0x4011, 0x0000, 0xC0A8, 0x0001, 0xC0A8, 0x00C7}, جوڑ = 0;
  لكل (صحيح index = 0; index < 10; index++) جوڑ += لفظاں[index];
  طالما (جوڑ >> 16) جوڑ = (جوڑ & 0xFFFF) + (جوڑ >> 16);
  لکھو("%04X\n", ~جوڑ & 0xFFFF);
  أرجع 0;
}
