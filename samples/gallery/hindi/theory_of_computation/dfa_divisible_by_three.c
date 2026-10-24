#समावेश <stdio.h>
/* a DFA over binary strings that accepts multiples of three */
पूर्णांक accepts(स्थिर अक्षर *word) {
  पूर्णांक state = 0;
  क्रम (पूर्णांक index = 0; word[index]; index++) state = (state * 2 + (word[index] - '0')) % 3;
  वापस state == 0;
}
पूर्णांक मुख्य(व्योम) { म_लिखो("%d %d %d %d\n", accepts("110"), accepts("111"), accepts("1001"), accepts("0")); वापस 0; }
