#समावेश <stdio.h>
/* CPU scheduling: average waiting time under FCFS, SJF and priority (all jobs arrive at time 0) */
द्विगुन average(पूर्णांक order[], पूर्णांक burst[], पूर्णांक count) {
  पूर्णांक समय = 0, waiting = 0;
  क्रम (पूर्णांक index = 0; index < count; index++) { waiting += समय; समय += burst[order[index]]; }
  वापस (द्विगुन)waiting / count;
}
पूर्णांक मुख्य(व्योम) {
  पूर्णांक burst[5] = {10, 1, 2, 1, 5}, priority[5] = {3, 1, 4, 5, 2};          /* smaller priority runs first */
  पूर्णांक arrival[5] = {0, 1, 2, 3, 4}, shortest[5], urgent[5];
  क्रम (पूर्णांक index = 0; index < 5; index++) shortest[index] = urgent[index] = index;
  क्रम (पूर्णांक first = 0; first < 5; first++)
    क्रम (पूर्णांक second = first + 1; second < 5; second++) {
      अगर (burst[shortest[second]] < burst[shortest[first]]) { पूर्णांक अस्थायी = shortest[first]; shortest[first] = shortest[second]; shortest[second] = अस्थायी; }
      अगर (priority[urgent[second]] < priority[urgent[first]]) { पूर्णांक अस्थायी = urgent[first]; urgent[first] = urgent[second]; urgent[second] = अस्थायी; }
    }
  म_लिखो("%.1f %.1f %.1f\n", average(arrival, burst, 5), average(shortest, burst, 5), average(urgent, burst, 5));
  वापस 0;
}
