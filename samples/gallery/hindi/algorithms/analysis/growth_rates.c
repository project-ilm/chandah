#समावेश <stdio.h>
/* asymptotic analysis: count the basic steps of linear search, binary search and insertion sort as the size grows */
पूर्णांक मुख्य(व्योम) {
  क्रम (पूर्णांक आकार = 16; आकार <= 4096; आकार *= 4) {
    दीर्घ linear = आकार, binary = 0, sorting = 0;
    क्रम (पूर्णांक low = 0, high = आकार - 1; low <= high; binary++) { पूर्णांक middle = (low + high) / 2; अगर (middle < आकार - 1) low = middle + 1; अन्यथा high = middle - 1; }
    क्रम (पूर्णांक अग्र = 1; अग्र < आकार; अग्र++) sorting += अग्र;           /* worst case: reverse order */
    म_लिखो("%d: %ld %ld %ld\n", आकार, linear, binary, sorting);
  }
  वापस 0;
}
