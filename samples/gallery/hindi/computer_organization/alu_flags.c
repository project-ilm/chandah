#समावेश <stdio.h>
/* the ALU: eight-bit addition and subtraction with zero, sign, carry and overflow flags */
व्योम operate(पूर्णांक first, पूर्णांक second, पूर्णांक subtract) {
  पूर्णांक दक्षिण = subtract ? (~second & 0xFF) : second, योग_2 = first + दक्षिण + subtract;
  पूर्णांक परिणाम = योग_2 & 0xFF, carry = योग_2 >> 8;
  पूर्णांक overflow = !((first ^ दक्षिण) & 0x80) && ((first ^ परिणाम) & 0x80);
  म_लिखो("%02X zero %d sign %d carry %d overflow %d\n", परिणाम, परिणाम == 0, परिणाम >> 7, carry, overflow);
}
पूर्णांक मुख्य(व्योम) { operate(0x70, 0x20, 0); operate(0x30, 0x30, 1); operate(0xF0, 0x20, 0); वापस 0; }
