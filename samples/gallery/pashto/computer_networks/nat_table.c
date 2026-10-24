#ضمن <stdio.h>
/* NAT: private address and port pairs mapped to ports of one public address, both ways */
صحيح اصلي(فراغ) {
  بینښه شخصي_پته[3] = {0xC0A80002, 0xC0A80003, 0xC0A80002}, شخصي_پورټ[3] = {5000, 5000, 6000}, عامه_پورټ[3];
  صحيح شمېر = 0;
  لكل (صحيح index = 0; index < 3; index++) { عامه_پورټ[شمېر++] = 40000 + index; چاپ_کړه("192.168.0.%u:%u -> 203.0.113.9:%u\n", شخصي_پته[index] & 255, شخصي_پورټ[index], عامه_پورټ[index]); }
  بینښه رارسېدونکی = 40001;
  لكل (صحيح index = 0; index < شمېر; index++)
    إذا (عامه_پورټ[index] == رارسېدونکی) چاپ_کړه("reply to %u goes to 192.168.0.%u:%u\n", رارسېدونکی, شخصي_پته[index] & 255, شخصي_پورټ[index]);
  أرجع 0;
}
