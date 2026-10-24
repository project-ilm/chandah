#समावेश <stdio.h>
/* greedy: Huffman coding; merge the two lightest trees until one is left, then read each symbol's code length */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक weight[11] = {5, 9, 12, 13, 16, 45}, parent[11], active[11] = {1, 1, 1, 1, 1, 1}, count = 6, योग_2 = 0;
  क्रम (पूर्णांक round = 0; round < 5; round++) {
    पूर्णांक first = -1, second = -1;
    क्रम (पूर्णांक नोड = 0; नोड < count; नोड++) {
      अगर (!active[नोड]) जारी;
      अगर (first < 0 || weight[नोड] < weight[first]) { second = first; first = नोड; }
      अन्यथा अगर (second < 0 || weight[नोड] < weight[second]) second = नोड;
    }
    weight[count] = weight[first] + weight[second]; active[count] = 1;
    parent[first] = parent[second] = count; active[first] = active[second] = 0; count++;
  }
  क्रम (पूर्णांक symbol = 0; symbol < 6; symbol++) {
    पूर्णांक लंबाई = 0;
    क्रम (पूर्णांक नोड = symbol; नोड != count - 1; नोड = parent[नोड]) लंबाई++;
    म_लिखो("%d ", लंबाई); योग_2 += लंबाई * weight[symbol];
  }
  म_लिखो("\nbits %d\n", योग_2);
  वापस 0;
}
