#समावेश <stdio.h>
/* regular expressions: a matcher for literals, . and * (with ^ and $ anchors) */
पूर्णांक match_here(स्थिर अक्षर *pattern, स्थिर अक्षर *text);
पूर्णांक match_star(पूर्णांक symbol, स्थिर अक्षर *pattern, स्थिर अक्षर *text) {
  करो { अगर (match_here(pattern, text)) वापस 1; } जबतक (*text != '\0' && (*text++ == symbol || symbol == '.'));
  वापस 0;
}
पूर्णांक match_here(स्थिर अक्षर *pattern, स्थिर अक्षर *text) {
  अगर (pattern[0] == '\0') वापस 1;
  अगर (pattern[1] == '*') वापस match_star(pattern[0], pattern + 2, text);
  अगर (pattern[0] == '$' && pattern[1] == '\0') वापस *text == '\0';
  अगर (*text != '\0' && (pattern[0] == '.' || pattern[0] == *text)) वापस match_here(pattern + 1, text + 1);
  वापस 0;
}
पूर्णांक match(स्थिर अक्षर *pattern, स्थिर अक्षर *text) {
  अगर (pattern[0] == '^') वापस match_here(pattern + 1, text);
  करो { अगर (match_here(pattern, text)) वापस 1; } जबतक (*text++ != '\0');
  वापस 0;
}
पूर्णांक मुख्य(व्योम) { म_लिखो("%d %d %d %d\n", match("^ab*c$", "abbbc"), match("a.c", "xxabcxx"), match("^ab*c$", "abd"), match("b*$", "")); वापस 0; }
