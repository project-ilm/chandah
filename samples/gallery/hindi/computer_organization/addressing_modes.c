#समावेश <stdio.h>
/* instruction sets: an accumulator machine with immediate, direct, indirect and indexed addressing */
क्रमागत { IMMEDIATE, DIRECT, INDIRECT, INDEXED };
पूर्णांक memory[16] = {0, 0, 0, 0, 0, 0, 0, 0, 40, 11, 12, 5, 7, 0, 0, 0}, accumulator = 0, सूचकांक_register = 2;
पूर्णांक operand(पूर्णांक kind, पूर्णांक field) {
  चयन (kind) {
    हाल IMMEDIATE: वापस field;
    हाल DIRECT: वापस memory[field];
    हाल INDIRECT: वापस memory[memory[field]];
    शेष: वापस memory[field + सूचकांक_register];
  }
}
पूर्णांक मुख्य(व्योम) {
  पूर्णांक program[4][3] = {{0, IMMEDIATE, 5}, {1, DIRECT, 8}, {1, INDIRECT, 9}, {1, INDEXED, 10}};   /* load, add, add, add */
  क्रम (पूर्णांक step = 0; step < 4; step++) {
    पूर्णांक मान = operand(program[step][1], program[step][2]);
    accumulator = program[step][0] == 0 ? मान : accumulator + मान;
    म_लिखो("%d ", accumulator);
  }
  म_लिखो("\n");
  वापस 0;
}
