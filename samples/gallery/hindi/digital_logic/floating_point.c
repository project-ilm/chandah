#समावेश <stdio.h>
#समावेश <string.h>
/* number representation: the sign, exponent and fraction of an IEEE 754 single-precision number */
पूर्णांक मुख्य(व्योम) {
  भग्न number = -6.25f;
  अचिन्हित bits;
  स_नकल(&bits, &number, माप bits);
  म_लिखो("sign %u exponent %u fraction %06X\n", bits >> 31, ((bits >> 23) & 0xFF) - 127, bits & 0x7FFFFF);
  वापस 0;
}
