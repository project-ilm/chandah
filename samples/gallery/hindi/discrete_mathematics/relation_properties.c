#समावेश <stdio.h>
/* sets and relations: is a relation on {0,1,2,3} reflexive, symmetric, antisymmetric, transitive? */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक relation[4][4] = {{1,1,0,0},{0,1,1,0},{0,0,1,1},{0,0,0,1}};
  पूर्णांक reflexive = 1, symmetric = 1, antisymmetric = 1, transitive = 1;
  क्रम (पूर्णांक first = 0; first < 4; first++) {
    reflexive &= relation[first][first];
    क्रम (पूर्णांक second = 0; second < 4; second++) {
      अगर (relation[first][second] != relation[second][first]) symmetric = 0;
      अगर (first != second && relation[first][second] && relation[second][first]) antisymmetric = 0;
      क्रम (पूर्णांक third = 0; third < 4; third++)
        अगर (relation[first][second] && relation[second][third] && !relation[first][third]) transitive = 0;
    }
  }
  म_लिखो("%d %d %d %d\n", reflexive, symmetric, antisymmetric, transitive);
  वापस 0;
}
