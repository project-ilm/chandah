#अन्तर्भाव <stdio.h>
/* instruction pipelining: a five-stage pipeline with forwarding stalls one cycle after each load whose result is used next */
पूर्णाङ्क मुख्यम्(शून्य) {
  पूर्णाङ्क आरोपय[] = {1, 0, 1, 0, 0, 1, 0}, उपयुङ्क्ते_पूर्वः[] = {0, 1, 0, 0, 1, 0, 1}, गणना_2 = 7, विरामाः = 0;
  प्रति (पूर्णाङ्क index = 1; index < गणना_2; index++) यदि (आरोपय[index - 1] && उपयुङ्क्ते_पूर्वः[index]) विरामाः++;
  प्रारूप_लिख("cycles %d stalls %d\n", 5 + (गणना_2 - 1) + विरामाः, विरामाः);
  प्रत्यागम 0;
}
