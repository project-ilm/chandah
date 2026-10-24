#समावेश <stdio.h>
/* stack: balanced brackets */
पूर्णांक मुख्य(व्योम) {
  अक्षर text[] = "{[()()]}", stack[32];
  पूर्णांक top = 0, balanced = 1;
  क्रम (पूर्णांक index = 0; text[index]; index++) {
    अक्षर symbol = text[index];
    अगर (symbol == '(' || symbol == '[' || symbol == '{') stack[top++] = symbol;
    अन्यथा अगर (top == 0 || (symbol == ')' && stack[top - 1] != '(') || (symbol == ']' && stack[top - 1] != '[') || (symbol == '}' && stack[top - 1] != '{')) { balanced = 0; अवरोध; }
    अन्यथा top--;
  }
  म_लिखो("%s\n", balanced && top == 0 ? "balanced" : "unbalanced");
  वापस 0;
}
