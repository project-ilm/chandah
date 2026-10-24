#समावेश <stdio.h>
#समावेश <math.h>
/* probability: uniform, exponential and normal samples from a fixed linear congruential generator, and their means */
अचिन्हित दीर्घ seed = 12345;
द्विगुन uniform(व्योम) { seed = (seed * 1103515245UL + 12345UL) % 2147483648UL; वापस (seed + 0.5) / 2147483648.0; }
पूर्णांक मुख्य(व्योम) {
  द्विगुन योग_uniform = 0, योग_exponential = 0, योग_normal = 0;
  क्रम (पूर्णांक index = 0; index < 20000; index++) {
    योग_uniform += uniform();
    योग_exponential += -log(uniform()) / 2.0;                                /* rate 2 */
    द्विगुन first = uniform(), second = uniform();
    योग_normal += 10 + 3 * वर्ग_मूल(-2 * log(first)) * cos(2 * 3.14159265358979 * second);   /* mean 10 */
  }
  म_लिखो("%.2f %.2f %.1f\n", योग_uniform / 20000, योग_exponential / 20000, योग_normal / 20000);
  वापस 0;
}
