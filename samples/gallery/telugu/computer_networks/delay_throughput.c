#అన్తర్భావ <stdio.h>
/* switching performance: transmission and propagation delay, and stop-and-wait link utilisation */
పూర్ణాంకం ప్రధాన(శూన్య) {
  ద్విగుణ కొలత = 1000 * 8, రేటు = 1e6, దూరం = 2e6, వేగం = 2e8;   /* bits, bits per second, metres, metres per second */
  ద్విగుణ సంప్రేషణ = కొలత / రేటు, ప్రసరణ = దూరం / వేగం;
  రాయి("%.1f ms %.1f ms %.2f\n", సంప్రేషణ * 1000, ప్రసరణ * 1000, సంప్రేషణ / (సంప్రేషణ + 2 * ప్రసరణ));
  తిరిగి 0;
}
