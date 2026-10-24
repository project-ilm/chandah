#شامل <stdio.h>
/* NAT: private address and port pairs mapped to ports of one public address, both ways */
صحیح مین(خالی) {
  غیرعلامتی نجی_پتہ[3] = {0xC0A80002, 0xC0A80003, 0xC0A80002}, نجی_پورٹ[3] = {5000, 5000, 6000}, عوامی_پورٹ[3];
  صحیح گنتی = 0;
  برائے (صحیح index = 0; index < 3; index++) { عوامی_پورٹ[گنتی++] = 40000 + index; لکھو("192.168.0.%u:%u -> 203.0.113.9:%u\n", نجی_پتہ[index] & 255, نجی_پورٹ[index], عوامی_پورٹ[index]); }
  غیرعلامتی آنے_والا = 40001;
  برائے (صحیح index = 0; index < گنتی; index++)
    اگر (عوامی_پورٹ[index] == آنے_والا) لکھو("reply to %u goes to 192.168.0.%u:%u\n", آنے_والا, نجی_پتہ[index] & 255, نجی_پورٹ[index]);
  واپس 0;
}
