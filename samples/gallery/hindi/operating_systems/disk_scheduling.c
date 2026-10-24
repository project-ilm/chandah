#समावेश <stdio.h>
#समावेश <stdlib.h>
/* I/O scheduling: total head movement under FCFS, SSTF and SCAN (towards larger cylinders first), from cylinder 53 */
पूर्णांक requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
पूर्णांक मुख्य(व्योम) {
  पूर्णांक in_order = 0, nearest_first = 0, scan = 0, शीर्ष = 53, done[8] = {0};
  क्रम (पूर्णांक index = 0; index < 8; index++) { in_order += असल(requests[index] - शीर्ष); शीर्ष = requests[index]; }
  शीर्ष = 53;
  क्रम (पूर्णांक round = 0; round < 8; round++) {
    पूर्णांक nearest = -1;
    क्रम (पूर्णांक index = 0; index < 8; index++) अगर (!done[index] && (nearest < 0 || असल(requests[index] - शीर्ष) < असल(requests[nearest] - शीर्ष))) nearest = index;
    nearest_first += असल(requests[nearest] - शीर्ष); शीर्ष = requests[nearest]; done[nearest] = 1;
  }
  पूर्णांक lowest = 199;
  क्रम (पूर्णांक index = 0; index < 8; index++) अगर (requests[index] < lowest) lowest = requests[index];
  scan = (199 - 53) + (199 - lowest);
  म_लिखो("%d %d %d\n", in_order, nearest_first, scan);
  वापस 0;
}
