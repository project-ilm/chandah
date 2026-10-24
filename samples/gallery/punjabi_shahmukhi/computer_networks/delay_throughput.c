#ضمن <stdio.h>
/* switching performance: transmission and propagation delay, and stop-and-wait link utilisation */
صحيح مکھ(فراغ) {
  مزدوج ناپ = 1000 * 8, شرح = 1e6, فاصلہ = 2e6, رفتار = 2e8;   /* bits, bits per second, metres, metres per second */
  مزدوج ترسیل = ناپ / شرح, پسار = فاصلہ / رفتار;
  لکھو("%.1f ms %.1f ms %.2f\n", ترسیل * 1000, پسار * 1000, ترسیل / (ترسیل + 2 * پسار));
  أرجع 0;
}
