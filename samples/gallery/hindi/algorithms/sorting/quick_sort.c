#समावेश <stdio.h>
/* quick sort, Lomuto partition */
व्योम swap(पूर्णांक *first, पूर्णांक *second) { पूर्णांक अस्थायी = *first; *first = *second; *second = अस्थायी; }
पूर्णांक partition(पूर्णांक values[], पूर्णांक low, पूर्णांक high) {
  पूर्णांक pivot = values[high], index = low - 1;
  क्रम (पूर्णांक scan = low; scan < high; scan++)
    अगर (values[scan] <= pivot) { index++; swap(&values[index], &values[scan]); }
  swap(&values[index + 1], &values[high]);
  वापस index + 1;
}
व्योम quick_sort(पूर्णांक values[], पूर्णांक low, पूर्णांक high) {
  अगर (low < high) { पूर्णांक middle = partition(values, low, high); quick_sort(values, low, middle - 1); quick_sort(values, middle + 1, high); }
}
पूर्णांक मुख्य(व्योम) {
  पूर्णांक values[] = {29, 3, 72, 14, 8, 55, 1, 40}, count = 8;
  quick_sort(values, 0, count - 1);
  क्रम (पूर्णांक index = 0; index < count; index++) म_लिखो("%d ", values[index]);
  म_लिखो("\n");
  वापस 0;
}
