#समावेश <stdio.h>
/* binary search in a sorted array */
पूर्णांक binary_search(पूर्णांक values[], पूर्णांक count, पूर्णांक कुंजी) {
  पूर्णांक low = 0, high = count - 1;
  जबतक (low <= high) {
    पूर्णांक middle = low + (high - low) / 2;
    अगर (values[middle] == कुंजी) वापस middle;
    अगर (values[middle] < कुंजी) low = middle + 1; अन्यथा high = middle - 1;
  }
  वापस -1;
}
पूर्णांक मुख्य(व्योम) {
  पूर्णांक values[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  म_लिखो("%d %d\n", binary_search(values, 10, 23), binary_search(values, 10, 7));
  वापस 0;
}
