#समावेश <stdio.h>
/* maximum subarray sum, divide and conquer */
पूर्णांक largest(पूर्णांक first, पूर्णांक second) { वापस first > second ? first : second; }
पूर्णांक crossing(पूर्णांक values[], पूर्णांक low, पूर्णांक middle, पूर्णांक high) {
  पूर्णांक योग = 0, वाम = -100000, दक्षिण = -100000;
  क्रम (पूर्णांक index = middle; index >= low; index--) { योग += values[index]; वाम = largest(वाम, योग); }
  योग = 0;
  क्रम (पूर्णांक index = middle + 1; index <= high; index++) { योग += values[index]; दक्षिण = largest(दक्षिण, योग); }
  वापस वाम + दक्षिण;
}
पूर्णांक best(पूर्णांक values[], पूर्णांक low, पूर्णांक high) {
  अगर (low == high) वापस values[low];
  पूर्णांक middle = (low + high) / 2;
  वापस largest(largest(best(values, low, middle), best(values, middle + 1, high)), crossing(values, low, middle, high));
}
पूर्णांक मुख्य(व्योम) { पूर्णांक values[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; म_लिखो("%d\n", best(values, 0, 8)); वापस 0; }
