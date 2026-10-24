#include <stdio.h>
#include <ctype.h>
/* parsing: a recursive-descent parser that evaluates  expression -> term {+|- term},  term -> factor {*|/ factor} */
const char *text;
int expression(void);
int factor(void) {
  if (*text == '(') { text++; int value = expression(); text++; return value; }
  int value = 0;
  while (isdigit(*text)) value = value * 10 + (*text++ - '0');
  return value;
}
int term(void) { int value = factor(); while (*text == '*' || *text == '/') { char symbol = *text++; int right = factor(); value = symbol == '*' ? value * right : value / right; } return value; }
int expression(void) { int value = term(); while (*text == '+' || *text == '-') { char symbol = *text++; int right = term(); value = symbol == '+' ? value + right : value - right; } return value; }
int main(void) { text = "2*(3+4)-10/5"; printf("%d\n", expression()); return 0; }
