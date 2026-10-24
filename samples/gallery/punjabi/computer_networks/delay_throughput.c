#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* switching performance: transmission and propagation delay, and stop-and-wait link utilisation */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਦੁੱਗਣਾ ਮਾਪ = 1000 * 8, ਦਰ = 1e6, ਦੂਰੀ = 2e6, ਰਫਤਾਰ = 2e8;   /* bits, bits per second, metres, metres per second */
  ਦੁੱਗਣਾ ਸੰਚਾਰ = ਮਾਪ / ਦਰ, ਪ੍ਰਸਾਰ = ਦੂਰੀ / ਰਫਤਾਰ;
  ਲਿਖੋ("%.1f ms %.1f ms %.2f\n", ਸੰਚਾਰ * 1000, ਪ੍ਰਸਾਰ * 1000, ਸੰਚਾਰ / (ਸੰਚਾਰ + 2 * ਪ੍ਰਸਾਰ));
  ਵਾਪਸ 0;
}
