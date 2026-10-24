#समावेश <stdio.h>
/* pushdown automata: accept a^n b^n (n >= 1) with a stack, reading a's then b's */
पूर्णांक accepts(स्थिर अक्षर *word) {
  अक्षर stack[64]; पूर्णांक top = 0, state = 0, index = 0;           /* state 0 reads a's, state 1 reads b's */
  क्रम (; word[index]; index++) {
    अगर (state == 0 && word[index] == 'a') stack[top++] = 'A';
    अन्यथा अगर (word[index] == 'b' && top > 0 && stack[top - 1] == 'A') { state = 1; top--; }
    अन्यथा वापस 0;
  }
  वापस state == 1 && top == 0;
}
पूर्णांक मुख्य(व्योम) { म_लिखो("%d %d %d %d\n", accepts("ab"), accepts("aaabbb"), accepts("aabbb"), accepts("abab")); वापस 0; }
