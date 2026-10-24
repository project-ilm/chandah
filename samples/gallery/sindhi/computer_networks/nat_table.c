#ضمن <stdio.h>
/* NAT: private address and port pairs mapped to ports of one public address, both ways */
صحيح مکيه(فراغ) {
  بنانشان ذاتي_پتو[3] = {0xC0A80002, 0xC0A80003, 0xC0A80002}, ذاتي_پورٽ[3] = {5000, 5000, 6000}, عوامي_پورٽ[3];
  صحيح ڳڻپ = 0;
  لكل (صحيح index = 0; index < 3; index++) { عوامي_پورٽ[ڳڻپ++] = 40000 + index; لکو("192.168.0.%u:%u -> 203.0.113.9:%u\n", ذاتي_پتو[index] & 255, ذاتي_پورٽ[index], عوامي_پورٽ[index]); }
  بنانشان پهچندڙ = 40001;
  لكل (صحيح index = 0; index < ڳڻپ; index++)
    إذا (عوامي_پورٽ[index] == پهچندڙ) لکو("reply to %u goes to 192.168.0.%u:%u\n", پهچندڙ, ذاتي_پتو[index] & 255, ذاتي_پورٽ[index]);
  أرجع 0;
}
