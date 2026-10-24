#ضمن <stdio.h>
/* switching performance: transmission and propagation delay, and stop-and-wait link utilisation */
صحيح اصلي(فراغ) {
  مزدوج اندازه = 1000 * 8, شرح = 1e6, واټن = 2e6, چټکتیا = 2e8;   /* bits, bits per second, metres, metres per second */
  مزدوج لېږدونه = اندازه / شرح, انتشار = واټن / چټکتیا;
  چاپ_کړه("%.1f ms %.1f ms %.2f\n", لېږدونه * 1000, انتشار * 1000, لېږدونه / (لېږدونه + 2 * انتشار));
  أرجع 0;
}
