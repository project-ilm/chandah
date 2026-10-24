#समावेश <stdio.h>
#समावेश <ctype.h>
/* evaluate a postfix (reverse Polish) expression with a stack */
पूर्णांक मुख्य(व्योम) {
  अक्षर expression[] = "3 4 + 2 * 7 -";
  पूर्णांक stack[16], top = 0;
  क्रम (पूर्णांक index = 0; expression[index]; index++) {
    अक्षर symbol = expression[index];
    अगर (है_अंक(symbol)) stack[top++] = symbol - '0';
    अन्यथा अगर (symbol != ' ') {
      पूर्णांक दक्षिण = stack[--top], वाम = stack[--top];
      stack[top++] = symbol == '+' ? वाम + दक्षिण : symbol == '-' ? वाम - दक्षिण : symbol == '*' ? वाम * दक्षिण : वाम / दक्षिण;
    }
  }
  म_लिखो("%d\n", stack[0]);
  वापस 0;
}
