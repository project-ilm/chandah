#समावेश <stdio.h>
#समावेश <ctype.h>
/* parsing: a recursive-descent parser that evaluates  expression -> term {+|- term},  term -> factor {*|/ factor} */
स्थिर अक्षर *text;
पूर्णांक expression(व्योम);
पूर्णांक factor(व्योम) {
  अगर (*text == '(') { text++; पूर्णांक मान = expression(); text++; वापस मान; }
  पूर्णांक मान = 0;
  जबतक (है_अंक(*text)) मान = मान * 10 + (*text++ - '0');
  वापस मान;
}
पूर्णांक term(व्योम) { पूर्णांक मान = factor(); जबतक (*text == '*' || *text == '/') { अक्षर symbol = *text++; पूर्णांक दक्षिण = factor(); मान = symbol == '*' ? मान * दक्षिण : मान / दक्षिण; } वापस मान; }
पूर्णांक expression(व्योम) { पूर्णांक मान = term(); जबतक (*text == '+' || *text == '-') { अक्षर symbol = *text++; पूर्णांक दक्षिण = term(); मान = symbol == '+' ? मान + दक्षिण : मान - दक्षिण; } वापस मान; }
पूर्णांक मुख्य(व्योम) { text = "2*(3+4)-10/5"; म_लिखो("%d\n", expression()); वापस 0; }
