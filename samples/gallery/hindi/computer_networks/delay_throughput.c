#समावेश <stdio.h>
/* switching performance: transmission and propagation delay, and stop-and-wait link utilisation */
पूर्णांक मुख्य(व्योम) {
  द्विगुन आकार = 1000 * 8, rate = 1e6, distance = 2e6, speed = 2e8;   /* bits, bits per second, metres, metres per second */
  द्विगुन transmission = आकार / rate, propagation = distance / speed;
  म_लिखो("%.1f ms %.1f ms %.2f\n", transmission * 1000, propagation * 1000, transmission / (transmission + 2 * propagation));
  वापस 0;
}
