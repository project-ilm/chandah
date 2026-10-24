#समावेश <stdio.h>
/* probability: Bayes' theorem for a test with known sensitivity and false-positive rate */
पूर्णांक मुख्य(व्योम) {
  द्विगुन prior = 0.01, sensitivity = 0.95, false_positive = 0.05;
  द्विगुन evidence = sensitivity * prior + false_positive * (1 - prior);
  म_लिखो("%.4f\n", sensitivity * prior / evidence);
  वापस 0;
}
