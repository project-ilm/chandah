#समावेश <stdio.h>
/* calculus: integrate x*x from 0 to 3 by Simpson's rule */
द्विगुन curve(द्विगुन point) { वापस point * point; }
पूर्णांक मुख्य(व्योम) {
  द्विगुन low = 0, high = 3, width = (high - low) / 6, योग_2 = curve(low) + curve(high);
  क्रम (पूर्णांक step = 1; step < 6; step++) योग_2 += (step % 2 ? 4 : 2) * curve(low + step * width);
  म_लिखो("%.4f\n", योग_2 * width / 3);
  वापस 0;
}
