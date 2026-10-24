#समावेश <stdio.h>
/* the preprocessor: object-like and function-like macros, and conditional compilation */
#घोषणा आकार_2 5
#घोषणा SQUARE(मान) ((मान) * (मान))
#अगर_अघोषित LIMIT
#घोषणा LIMIT 20
#पूर्ण_अगर
पूर्णांक मुख्य(व्योम) {
  पूर्णांक योग_2 = 0;
  क्रम (पूर्णांक index = 1; index <= आकार_2; index++) योग_2 += SQUARE(index);
#अगर_घोषित LIMIT
  म_लिखो("%d %d\n", योग_2, योग_2 > LIMIT);
#अन्यथा
  म_लिखो("%d\n", योग_2);
#पूर्ण_अगर
  वापस 0;
}
