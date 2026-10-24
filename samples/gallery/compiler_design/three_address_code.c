#अन्तर्भाव <stdio.h>
/* intermediate code generation: three-address code for a = b * c + b * d, with common subexpression reuse shown */
पूर्णाङ्क मुख्यम्(शून्य) {
  ध्रुव वर्ण *संहिता[] = {"t1 = b * c", "t2 = b * d", "t3 = t1 + t2", "a = t3"};
  प्रति (पूर्णाङ्क index = 0; index < 4; index++) प्रारूप_लिख("%s\n", संहिता[index]);
  प्रत्यागम 0;
}
