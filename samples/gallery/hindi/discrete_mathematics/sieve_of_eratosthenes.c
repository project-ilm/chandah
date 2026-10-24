#समावेश <stdio.h>
/* primes below 60 */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक composite[60] = {0};
  क्रम (पूर्णांक number = 2; number < 60; number++) {
    अगर (composite[number]) जारी;
    म_लिखो("%d ", number);
    क्रम (पूर्णांक multiple = number * number; multiple < 60; multiple += number) composite[multiple] = 1;
  }
  म_लिखो("\n");
  वापस 0;
}
