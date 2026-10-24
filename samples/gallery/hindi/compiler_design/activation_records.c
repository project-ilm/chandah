#समावेश <stdio.h>
/* runtime environments: the activation records a recursive factorial pushes, kept on an explicit stack */
काष्ठा frame { पूर्णांक argument, परिणाम, depth; } stack[16];
पूर्णांक top = 0, deepest = 0;
पूर्णांक factorial(पूर्णांक argument) {
  काष्ठा frame *record = &stack[top++];
  record->argument = argument; record->depth = top;
  अगर (top > deepest) deepest = top;
  record->परिणाम = argument <= 1 ? 1 : argument * factorial(argument - 1);
  top--;
  वापस record->परिणाम;
}
पूर्णांक मुख्य(व्योम) {
  पूर्णांक परिणाम = factorial(5);
  क्रम (पूर्णांक index = 0; index < deepest; index++) म_लिखो("%d:%d ", stack[index].argument, stack[index].परिणाम);
  म_लिखो("\nresult %d, deepest %d frames\n", परिणाम, deepest);
  वापस 0;
}
