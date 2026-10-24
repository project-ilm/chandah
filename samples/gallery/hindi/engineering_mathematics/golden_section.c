#समावेश <stdio.h>
#समावेश <math.h>
/* calculus: the minimum of (x - 2)^2 + 1 on [0, 5] by golden-section search */
द्विगुन curve(द्विगुन point) { वापस (point - 2) * (point - 2) + 1; }
पूर्णांक मुख्य(व्योम) {
  द्विगुन ratio = (वर्ग_मूल(5) - 1) / 2, low = 0, high = 5;
  क्रम (पूर्णांक step = 0; step < 60; step++) {
    द्विगुन first = high - ratio * (high - low), second = low + ratio * (high - low);
    अगर (curve(first) < curve(second)) high = second; अन्यथा low = first;
  }
  म_लिखो("%.4f %.4f\n", (low + high) / 2, curve((low + high) / 2));
  वापस 0;
}
