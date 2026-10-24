#समावेश <stdio.h>
/* TCP congestion control: slow start, congestion avoidance, and a timeout at round 8 */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक window = 1, threshold = 16;
  क्रम (पूर्णांक round = 1; round <= 12; round++) {
    म_लिखो("%d ", window);
    अगर (round == 8) { threshold = window / 2; window = 1; }
    अन्यथा अगर (window < threshold) window *= 2;
    अन्यथा window += 1;
  }
  म_लिखो("\n");
  वापस 0;
}
