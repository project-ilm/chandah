#समावेश <stdio.h>
/* intermediate code generation: three-address code for a = b * c + b * d, with common subexpression reuse shown */
पूर्णांक मुख्य(व्योम) {
  स्थिर अक्षर *code[] = {"t1 = b * c", "t2 = b * d", "t3 = t1 + t2", "a = t3"};
  क्रम (पूर्णांक index = 0; index < 4; index++) म_लिखो("%s\n", code[index]);
  वापस 0;
}
