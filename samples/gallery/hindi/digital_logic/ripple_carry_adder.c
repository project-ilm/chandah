#समावेश <stdio.h>
/* a four-bit ripple-carry adder built from full adders */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक first = 11, second = 6, carry = 0, योग = 0;
  क्रम (पूर्णांक bit = 0; bit < 4; bit++) {
    पूर्णांक a = (first >> bit) & 1, b = (second >> bit) & 1;
    योग |= (a ^ b ^ carry) << bit;
    carry = (a & b) | (carry & (a ^ b));
  }
  म_लिखो("%d carry %d\n", योग, carry);
  वापस 0;
}
