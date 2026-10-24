#समावेश <stdio.h>
/* propositional logic: the truth table of ((p -> q) and (q -> r)) -> (p -> r), and whether it is a tautology */
पूर्णांक implies(पूर्णांक first, पूर्णांक second) { वापस !first || second; }
पूर्णांक मुख्य(व्योम) {
  पूर्णांक tautology = 1;
  क्रम (पूर्णांक row = 0; row < 8; row++) {
    पूर्णांक p = (row >> 2) & 1, q = (row >> 1) & 1, r = row & 1;
    पूर्णांक मान = implies(implies(p, q) && implies(q, r), implies(p, r));
    म_लिखो("%d%d%d:%d ", p, q, r, मान);
    tautology &= मान;
  }
  म_लिखो("\n%s\n", tautology ? "tautology" : "not a tautology");
  वापस 0;
}
