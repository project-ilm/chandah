#समावेश <stdio.h>
#समावेश <string.h>
/* context-free grammars: CYK parsing for S->AB|BC, A->BA|a, B->CC|b, C->AB|a (symbols S=1, A=2, B=4, C=8 as bits) */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक rules[5][3] = {{1, 2, 4}, {1, 4, 8}, {2, 4, 2}, {4, 8, 8}, {8, 2, 4}};   /* head, first, second */
  स्थिर अक्षर *word = "baaba";
  पूर्णांक लंबाई = म_माप(word), table[8][8] = {{0}};
  क्रम (पूर्णांक index = 0; index < लंबाई; index++) table[index][index] = word[index] == 'a' ? (2 | 8) : 4;
  क्रम (पूर्णांक span = 2; span <= लंबाई; span++)
    क्रम (पूर्णांक start = 0; start + span - 1 < लंबाई; start++)
      क्रम (पूर्णांक split = start; split < start + span - 1; split++)
        क्रम (पूर्णांक rule = 0; rule < 5; rule++)
          अगर ((table[start][split] & rules[rule][1]) && (table[split + 1][start + span - 1] & rules[rule][2]))
            table[start][start + span - 1] |= rules[rule][0];
  म_लिखो("%s\n", table[0][लंबाई - 1] & 1 ? "accepted" : "rejected");
  वापस 0;
}
