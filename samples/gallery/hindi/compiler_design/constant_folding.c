#समावेश <stdio.h>
/* local optimisation: constant folding and propagation over three-address code (a, b, c, d are variables 0..3) */
पूर्णांक मुख्य(व्योम) {
  /* target = left op right; an operand below 100 is a constant, 100 + k is variable k */
  पूर्णांक code[4][4] = {{0, 4, '*', 2}, {1, 100, '+', 3}, {2, 101, '*', 100}, {3, 102, '-', 1}};
  पूर्णांक known[4] = {0}, मान[4];
  क्रम (पूर्णांक index = 0; index < 4; index++) {
    पूर्णांक वाम = code[index][1], दक्षिण = code[index][3], symbol = code[index][2];
    पूर्णांक वाम_known = वाम < 100 || known[वाम - 100], दक्षिण_known = दक्षिण < 100 || known[दक्षिण - 100];
    पूर्णांक first = वाम < 100 ? वाम : मान[वाम - 100], second = दक्षिण < 100 ? दक्षिण : मान[दक्षिण - 100];
    अगर (वाम_known && दक्षिण_known) {
      मान[code[index][0]] = symbol == '*' ? first * second : symbol == '+' ? first + second : first - second;
      known[code[index][0]] = 1;
      म_लिखो("%c = %d\n", 'a' + code[index][0], मान[code[index][0]]);
    }
  }
  वापस 0;
}
