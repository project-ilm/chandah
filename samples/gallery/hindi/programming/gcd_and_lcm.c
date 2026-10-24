#समावेश <stdio.h>
/* Euclid's algorithm */
पूर्णांक gcd(पूर्णांक first, पूर्णांक second) { वापस second == 0 ? first : gcd(second, first % second); }
पूर्णांक मुख्य(व्योम) { पूर्णांक first = 84, second = 36; म_लिखो("%d %d\n", gcd(first, second), first / gcd(first, second) * second); वापस 0; }
