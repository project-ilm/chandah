#ضمن <stdio.h>
#ضمن <string.h>
/* number representation: the sign, exponent and fraction of an IEEE 754 single-precision number */
صحيح اصلی(فراغ) {
  عائم شماره = -6.25f;
  بیعلامت بیتها;
  کپی_حافظه(&بیتها, &شماره, حجم بیتها);
  چاپ_کن("sign %u exponent %u fraction %06X\n", بیتها >> 31, ((بیتها >> 23) & 0xFF) - 127, بیتها & 0x7FFFFF);
  أرجع 0;
}
