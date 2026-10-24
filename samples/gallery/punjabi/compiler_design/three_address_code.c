#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* intermediate code generation: three-address code for a = b * c + b * d, with common subexpression reuse shown */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *ਕੋਡ[] = {"t1 = b * c", "t2 = b * d", "t3 = t1 + t2", "a = t3"};
  ਲਈ (ਪੂਰਨ index = 0; index < 4; index++) ਲਿਖੋ("%s\n", ਕੋਡ[index]);
  ਵਾਪਸ 0;
}
