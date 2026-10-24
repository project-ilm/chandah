#समावेश <stdio.h>
#समावेश <math.h>
/* calculus: a derivative by central differences, and the limit of sin(x)/x as x approaches 0 */
पूर्णांक मुख्य(व्योम) {
  द्विगुन point = 1.0, step = 1e-5;
  द्विगुन slope = (sin(point + step) - sin(point - step)) / (2 * step);
  म_लिखो("%.6f %.6f\n", slope, cos(point));
  क्रम (द्विगुन width = 0.1; width > 1e-4; width /= 10) म_लिखो("%.8f ", sin(width) / width);
  म_लिखो("\n");
  वापस 0;
}
