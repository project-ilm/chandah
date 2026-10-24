#ضمن <stdio.h>
/* NAT: private address and port pairs mapped to ports of one public address, both ways */
صحيح مکھ(فراغ) {
  بنانشانی نجی_پتہ[3] = {0xC0A80002, 0xC0A80003, 0xC0A80002}, نجی_پورٹ[3] = {5000, 5000, 6000}, عوامی_پورٹ[3];
  صحيح گنتی = 0;
  لكل (صحيح index = 0; index < 3; index++) { عوامی_پورٹ[گنتی++] = 40000 + index; لکھو("192.168.0.%u:%u -> 203.0.113.9:%u\n", نجی_پتہ[index] & 255, نجی_پورٹ[index], عوامی_پورٹ[index]); }
  بنانشانی آون_والا = 40001;
  لكل (صحيح index = 0; index < گنتی; index++)
    إذا (عوامی_پورٹ[index] == آون_والا) لکھو("reply to %u goes to 192.168.0.%u:%u\n", آون_والا, نجی_پتہ[index] & 255, نجی_پورٹ[index]);
  أرجع 0;
}
