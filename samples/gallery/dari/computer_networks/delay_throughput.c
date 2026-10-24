#ضمن <stdio.h>
/* switching performance: transmission and propagation delay, and stop-and-wait link utilisation */
صحيح اصلی(فراغ) {
  مزدوج اندازه = 1000 * 8, نرخ = 1e6, فاصله = 2e6, سرعت = 2e8;   /* bits, bits per second, metres, metres per second */
  مزدوج ارسال = اندازه / نرخ, انتشار = فاصله / سرعت;
  چاپ_کن("%.1f ms %.1f ms %.2f\n", ارسال * 1000, انتشار * 1000, ارسال / (ارسال + 2 * انتشار));
  أرجع 0;
}
