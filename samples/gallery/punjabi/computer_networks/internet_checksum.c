#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* the Internet checksum (one's complement sum of 16-bit words) */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਸ਼ਬਦਾਂ[] = {0x4500, 0x0073, 0x0000, 0x4000, 0x4011, 0x0000, 0xC0A8, 0x0001, 0xC0A8, 0x00C7}, ਜੋੜ = 0;
  ਲਈ (ਪੂਰਨ index = 0; index < 10; index++) ਜੋੜ += ਸ਼ਬਦਾਂ[index];
  ਜਦੋਂ (ਜੋੜ >> 16) ਜੋੜ = (ਜੋੜ & 0xFFFF) + (ਜੋੜ >> 16);
  ਲਿਖੋ("%04X\n", ~ਜੋੜ & 0xFFFF);
  ਵਾਪਸ 0;
}
