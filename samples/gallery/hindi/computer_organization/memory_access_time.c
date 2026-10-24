#समावेश <stdio.h>
/* memory hierarchy performance: average access time of two cache levels in front of main memory */
पूर्णांक मुख्य(व्योम) {
  द्विगुन first_time = 1, first_miss = 0.10, second_time = 10, second_miss = 0.20, memory_time = 100;
  द्विगुन hierarchical = first_time + first_miss * (second_time + second_miss * memory_time);
  द्विगुन simultaneous = (1 - first_miss) * first_time + first_miss * ((1 - second_miss) * second_time + second_miss * memory_time);
  म_लिखो("%.2f %.2f\n", hierarchical, simultaneous);
  वापस 0;
}
