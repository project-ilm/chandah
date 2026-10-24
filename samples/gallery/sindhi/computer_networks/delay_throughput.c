#ضمن <stdio.h>
/* switching performance: transmission and propagation delay, and stop-and-wait link utilisation */
صحيح مکيه(فراغ) {
  مزدوج سائيز = 1000 * 8, شرح = 1e6, مفاصلو = 2e6, رفتار = 2e8;   /* bits, bits per second, metres, metres per second */
  مزدوج ترسيل = سائيز / شرح, ڦهلاء = مفاصلو / رفتار;
  لکو("%.1f ms %.1f ms %.2f\n", ترسيل * 1000, ڦهلاء * 1000, ترسيل / (ترسيل + 2 * ڦهلاء));
  أرجع 0;
}
