#समावेश <stdio.h>
#समावेश <ctype.h>
/* syntax-directed translation: each grammar rule emits postfix as it is recognised */
स्थिर अक्षर *text;
व्योम expression(व्योम);
व्योम factor(व्योम) {
  अगर (*text == '(') { text++; expression(); text++; वापस; }
  जबतक (है_अंक(*text)) अक्षर_दो(*text++);
  अक्षर_दो(' ');
}
व्योम term(व्योम) { factor(); जबतक (*text == '*' || *text == '/') { अक्षर symbol = *text++; factor(); म_लिखो("%c ", symbol); } }
व्योम expression(व्योम) { term(); जबतक (*text == '+' || *text == '-') { अक्षर symbol = *text++; term(); म_लिखो("%c ", symbol); } }
पूर्णांक मुख्य(व्योम) { text = "2+3*4-(5-1)/2"; expression(); म_लिखो("\n"); वापस 0; }
