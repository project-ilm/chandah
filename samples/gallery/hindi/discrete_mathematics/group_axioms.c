#समावेश <stdio.h>
/* groups: check closure, associativity, identity and inverses for multiplication modulo a number */
पूर्णांक is_group(पूर्णांक आकार) {
  पूर्णांक identity = -1;
  क्रम (पूर्णांक first = 1; first < आकार; first++)
    क्रम (पूर्णांक second = 1; second < आकार; second++)
      अगर (first * second % आकार == 0) वापस 0;                         /* not closed on 1..size-1 */
  क्रम (पूर्णांक first = 1; first < आकार; first++)
    क्रम (पूर्णांक second = 1; second < आकार; second++)
      क्रम (पूर्णांक third = 1; third < आकार; third++)
        अगर (first * second % आकार * third % आकार != first * (second * third % आकार) % आकार) वापस 0;
  क्रम (पूर्णांक first = 1; first < आकार && identity < 0; first++) {
    पूर्णांक works = 1;
    क्रम (पूर्णांक second = 1; second < आकार; second++) अगर (first * second % आकार != second) works = 0;
    अगर (works) identity = first;
  }
  क्रम (पूर्णांक first = 1; first < आकार; first++) {
    पूर्णांक found = 0;
    क्रम (पूर्णांक second = 1; second < आकार; second++) अगर (first * second % आकार == identity) found = 1;
    अगर (!found) वापस 0;
  }
  वापस identity > 0;
}
पूर्णांक मुख्य(व्योम) { म_लिखो("%d %d %d\n", is_group(5), is_group(7), is_group(8)); वापस 0; }
