#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdint.h>
/* number representation: two's complement in eight bits, overflow, and fixed-point (Q4.4) multiplication */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  int8_t ਮੁੱਲ_ਇਕ = -5;
  ਪੂਰਨ ਜੋੜ = 100 + 50;
  ਪੂਰਨ ਉਛਾਲ = ਜੋੜ > 127 || ਜੋੜ < -128;
  ਪੂਰਨ ਪਹਿਲਾ = (ਪੂਰਨ)(2.5 * 16), ਦੂਜਾ = (ਪੂਰਨ)(1.75 * 16), ਗੁਣਨਫਲ = (ਪਹਿਲਾ * ਦੂਜਾ) >> 4;
  ਲਿਖੋ("%02X %d %d %.4f\n", (uint8_t)ਮੁੱਲ_ਇਕ, (int8_t)ਜੋੜ, ਉਛਾਲ, ਗੁਣਨਫਲ / 16.0);
  ਵਾਪਸ 0;
}
