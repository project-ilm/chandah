#شامل <stdio.h>
/* switching performance: transmission and propagation delay, and stop-and-wait link utilisation */
صحیح مین(خالی) {
  دوہرا سائز = 1000 * 8, شرح = 1e6, فاصلہ = 2e6, رفتار = 2e8;   /* bits, bits per second, metres, metres per second */
  دوہرا ترسیل = سائز / شرح, اشاعت = فاصلہ / رفتار;
  لکھو("%.1f ms %.1f ms %.2f\n", ترسیل * 1000, اشاعت * 1000, ترسیل / (ترسیل + 2 * اشاعت));
  واپس 0;
}
