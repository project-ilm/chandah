#include <stdio.h>
#include <ctype.h>
/* evaluate a postfix (reverse Polish) expression with a stack */
int main(void) {
  char expression[] = "3 4 + 2 * 7 -";
  int stack[16], top = 0;
  for (int index = 0; expression[index]; index++) {
    char symbol = expression[index];
    if (isdigit(symbol)) stack[top++] = symbol - '0';
    else if (symbol != ' ') {
      int right = stack[--top], left = stack[--top];
      stack[top++] = symbol == '+' ? left + right : symbol == '-' ? left - right : symbol == '*' ? left * right : left / right;
    }
  }
  printf("%d\n", stack[0]);
  return 0;
}
