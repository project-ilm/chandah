#समावेश <stdio.h>
#समावेश <string.h>
/* a Turing machine that adds one to a binary number written on its tape */
पूर्णांक मुख्य(व्योम) {
  अक्षर tape[16] = "_1011_";
  पूर्णांक शीर्ष = 4, state = 0, steps = 0;           /* state 0 carries, state 1 halts */
  जबतक (state == 0) {
    अगर (tape[शीर्ष] == '1') { tape[शीर्ष] = '0'; शीर्ष--; }
    अन्यथा { tape[शीर्ष] = '1'; state = 1; }
    steps++;
  }
  म_लिखो("%s %d\n", tape, steps);
  वापस 0;
}
