#समावेश <stdio.h>
#समावेश <math.h>
/* probability and statistics: mean, median, mode and standard deviation of sorted values */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक values[] = {2, 3, 3, 5, 7, 8, 8, 8, 9}, count = 9, mode = values[0], best = 0;
  द्विगुन योग_2 = 0, spread = 0;
  क्रम (पूर्णांक index = 0; index < count; index++) योग_2 += values[index];
  द्विगुन mean = योग_2 / count;
  क्रम (पूर्णांक index = 0; index < count; index++) spread += (values[index] - mean) * (values[index] - mean);
  क्रम (पूर्णांक index = 0, run = 1; index < count; index++, run = (index < count && values[index] == values[index - 1]) ? run + 1 : 1)
    अगर (run > best) { best = run; mode = values[index]; }
  म_लिखो("mean %.2f median %d mode %d deviation %.2f\n", mean, values[count / 2], mode, वर्ग_मूल(spread / count));
  वापस 0;
}
