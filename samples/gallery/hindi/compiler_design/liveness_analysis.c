#समावेश <stdio.h>
/* data-flow analysis: live variables over a control-flow graph, iterated to a fixed point (bits a=1, b=2, c=4, d=8) */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक uses[4] = {0, 1 | 2, 4, 1 | 8}, defines[4] = {1 | 2, 4, 8, 0};
  पूर्णांक successors[4][2] = {{1, -1}, {2, 3}, {1, -1}, {-1, -1}}, live_in[4] = {0}, live_out[4] = {0}, changed = 1, rounds = 0;
  जबतक (changed) {
    changed = 0; rounds++;
    क्रम (पूर्णांक block = 3; block >= 0; block--) {
      पूर्णांक out = 0;
      क्रम (पूर्णांक index = 0; index < 2; index++) अगर (successors[block][index] >= 0) out |= live_in[successors[block][index]];
      पूर्णांक in = uses[block] | (out & ~defines[block]);
      अगर (in != live_in[block] || out != live_out[block]) { live_in[block] = in; live_out[block] = out; changed = 1; }
    }
  }
  क्रम (पूर्णांक block = 0; block < 4; block++) {
    क्रम (पूर्णांक bit = 0; bit < 4; bit++) अगर (live_in[block] >> bit & 1) अक्षर_दो('a' + bit);
    अक्षर_दो(' ');
  }
  म_लिखो("\nrounds %d\n", rounds);
  वापस 0;
}
