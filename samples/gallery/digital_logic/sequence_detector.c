#अन्तर्भाव <stdio.h>
/* sequential circuits: a Moore state machine that detects 101 in a bit stream, overlaps allowed */
पूर्णाङ्क मुख्यम्(शून्य) {
  पूर्णाङ्क अग्रिमः[4][2] = {{0, 1}, {2, 1}, {0, 3}, {2, 1}};      /* states: none, seen 1, seen 10, seen 101 */
  ध्रुव वर्ण *प्रवाहः = "1101011010";
  पूर्णाङ्क state = 0;
  प्रति (पूर्णाङ्क index = 0; प्रवाहः[index]; index++) {
    state = अग्रिमः[state][प्रवाहः[index] - '0'];
    प्रारूप_लिख("%d", state == 3);
  }
  प्रारूप_लिख("\n");
  प्रत्यागम 0;
}
