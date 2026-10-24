#include <stdio.h>
/* stack: balanced brackets */
int main(void) {
  char text[] = "{[()()]}", stack[32];
  int top = 0, balanced = 1;
  for (int index = 0; text[index]; index++) {
    char symbol = text[index];
    if (symbol == '(' || symbol == '[' || symbol == '{') stack[top++] = symbol;
    else if (top == 0 || (symbol == ')' && stack[top - 1] != '(') || (symbol == ']' && stack[top - 1] != '[') || (symbol == '}' && stack[top - 1] != '{')) { balanced = 0; break; }
    else top--;
  }
  printf("%s\n", balanced && top == 0 ? "balanced" : "unbalanced");
  return 0;
}
