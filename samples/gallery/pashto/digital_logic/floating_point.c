#ضمن <stdio.h>
#ضمن <string.h>
/* number representation: the sign, exponent and fraction of an IEEE 754 single-precision number */
صحيح اصلي(فراغ) {
  عائم شمېره = -6.25f;
  بینښه بټونه;
  حافظه_نقل(&بټونه, &شمېره, حجم بټونه);
  چاپ_کړه("sign %u exponent %u fraction %06X\n", بټونه >> 31, ((بټونه >> 23) & 0xFF) - 127, بټونه & 0x7FFFFF);
  أرجع 0;
}
