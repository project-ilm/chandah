#समावेश <stdio.h>
/* recursion and memoisation: Fibonacci numbers */
दीर्घ memo[64];
दीर्घ fibonacci(पूर्णांक number) { अगर (number < 2) वापस number; अगर (memo[number]) वापस memo[number]; वापस memo[number] = fibonacci(number - 1) + fibonacci(number - 2); }
पूर्णांक मुख्य(व्योम) { क्रम (पूर्णांक number = 0; number <= 10; number++) म_लिखो("%ld ", fibonacci(number)); म_लिखो("\n%ld\n", fibonacci(50)); वापस 0; }
