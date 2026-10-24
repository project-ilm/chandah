#ضمن <stdio.h>
#ضمن <string.h>
/* number representation: the sign, exponent and fraction of an IEEE 754 single-precision number */
صحيح مکھ(فراغ) {
  عائم نمبر = -6.25f;
  بنانشانی بٹ;
  حافظہ_نقل(&بٹ, &نمبر, حجم بٹ);
  لکھو("sign %u exponent %u fraction %06X\n", بٹ >> 31, ((بٹ >> 23) & 0xFF) - 127, بٹ & 0x7FFFFF);
  أرجع 0;
}
