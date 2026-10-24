#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* probability: Bayes' theorem for a test with known sensitivity and false-positive rate */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਦੁੱਗਣਾ ਪੂਰਵ = 0.01, ਸੰਵੇਦਨਸ਼ੀਲਤਾ = 0.95, ਝੂਠਾ_ਸਕਾਰਾਤਮਕ = 0.05;
  ਦੁੱਗਣਾ ਸਬੂਤ = ਸੰਵੇਦਨਸ਼ੀਲਤਾ * ਪੂਰਵ + ਝੂਠਾ_ਸਕਾਰਾਤਮਕ * (1 - ਪੂਰਵ);
  ਲਿਖੋ("%.4f\n", ਸੰਵੇਦਨਸ਼ੀਲਤਾ * ਪੂਰਵ / ਸਬੂਤ);
  ਵਾਪਸ 0;
}
