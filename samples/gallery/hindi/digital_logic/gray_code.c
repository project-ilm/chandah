#समावेश <stdio.h>
/* binary to Gray code and back */
पूर्णांक मुख्य(व्योम) {
  क्रम (पूर्णांक number = 0; number < 8; number++) {
    पूर्णांक gray = number ^ (number >> 1), back = gray;
    क्रम (पूर्णांक shift = gray >> 1; shift; shift >>= 1) back ^= shift;
    म_लिखो("%d:%d:%d ", number, gray, back);
  }
  म_लिखो("\n");
  वापस 0;
}
