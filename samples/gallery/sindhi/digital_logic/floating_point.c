#ضمن <stdio.h>
#ضمن <string.h>
/* number representation: the sign, exponent and fraction of an IEEE 754 single-precision number */
صحيح مکيه(فراغ) {
  عائم نمبر = -6.25f;
  بنانشان بٽ;
  يادگيري_نقل(&بٽ, &نمبر, حجم بٽ);
  لکو("sign %u exponent %u fraction %06X\n", بٽ >> 31, ((بٽ >> 23) & 0xFF) - 127, بٽ & 0x7FFFFF);
  أرجع 0;
}
