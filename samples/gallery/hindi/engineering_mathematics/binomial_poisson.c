#समावेश <stdio.h>
#समावेश <math.h>
/* probability: binomial P(X = 3) with n = 10, p = 0.3, and Poisson P(X = 2) with rate 3 */
द्विगुन choose(पूर्णांक योग_2, पूर्णांक count) { द्विगुन परिणाम = 1; क्रम (पूर्णांक index = 1; index <= count; index++) परिणाम = परिणाम * (योग_2 - count + index) / index; वापस परिणाम; }
पूर्णांक मुख्य(व्योम) {
  द्विगुन binomial = choose(10, 3) * घात(0.3, 3) * घात(0.7, 7);
  द्विगुन poisson = exp(-3.0) * घात(3.0, 2) / 2;
  म_लिखो("%.4f %.4f\n", binomial, poisson);
  वापस 0;
}
