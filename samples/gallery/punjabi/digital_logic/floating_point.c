#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
/* number representation: the sign, exponent and fraction of an IEEE 754 single-precision number */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਦਸ਼ਮਲਵ ਨੰਬਰ = -6.25f;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਬਿੱਟ;
  ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ਬਿੱਟ, &ਨੰਬਰ, ਆਕਾਰ ਬਿੱਟ);
  ਲਿਖੋ("sign %u exponent %u fraction %06X\n", ਬਿੱਟ >> 31, ((ਬਿੱਟ >> 23) & 0xFF) - 127, ਬਿੱਟ & 0x7FFFFF);
  ਵਾਪਸ 0;
}
