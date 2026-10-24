#समावेश <stdio.h>
#समावेश <ctype.h>
/* a hand-written lexer: identifiers, numbers and operators */
पूर्णांक मुख्य(व्योम) {
  अक्षर source[] = "total = count1 + 42 * rate;";
  पूर्णांक index = 0, tokens = 0;
  जबतक (source[index]) {
    अगर (है_खाली(source[index])) { index++; जारी; }
    पूर्णांक start = index;
    अगर (है_अक्षर(source[index])) { जबतक (है_अक्षर_अंक(source[index])) index++; म_लिखो("ID "); }
    अन्यथा अगर (है_अंक(source[index])) { जबतक (है_अंक(source[index])) index++; म_लिखो("NUM "); }
    अन्यथा { index++; म_लिखो("OP "); }
    tokens++;
    (व्योम)start;
  }
  म_लिखो("\n%d\n", tokens);
  वापस 0;
}
