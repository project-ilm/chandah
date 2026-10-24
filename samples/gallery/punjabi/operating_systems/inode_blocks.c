#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* file systems: the largest file an inode with 12 direct, one single, one double and one triple indirect pointer can map */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਲੰਮਾ ਲੰਮਾ ਖੰਡ = 1024, ਸੂਚਕ_ਸਾਰੇ = ਖੰਡ / 4;
  ਲੰਮਾ ਲੰਮਾ ਖੰਡਾਂ = 12 + ਸੂਚਕ_ਸਾਰੇ + ਸੂਚਕ_ਸਾਰੇ * ਸੂਚਕ_ਸਾਰੇ + ਸੂਚਕ_ਸਾਰੇ * ਸੂਚਕ_ਸਾਰੇ * ਸੂਚਕ_ਸਾਰੇ;
  ਲਿਖੋ("%lld blocks, %lld bytes\n", ਖੰਡਾਂ, ਖੰਡਾਂ * ਖੰਡ);
  ਵਾਪਸ 0;
}
