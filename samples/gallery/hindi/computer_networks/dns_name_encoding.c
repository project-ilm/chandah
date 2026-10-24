#समावेश <stdio.h>
#समावेश <string.h>
/* DNS: a domain name in the wire format of a query, each label preceded by its length, ending with zero */
पूर्णांक मुख्य(व्योम) {
  स्थिर अक्षर *text = "www.example.com";
  अचिन्हित अक्षर out[64]; पूर्णांक आकार = 0, start = 0;
  क्रम (पूर्णांक index = 0; ; index++)
    अगर (text[index] == '.' || text[index] == '\0') {
      out[आकार++] = index - start;
      स_नकल(out + आकार, text + start, index - start); आकार += index - start;
      start = index + 1;
      अगर (text[index] == '\0') अवरोध;
    }
  out[आकार++] = 0;
  क्रम (पूर्णांक index = 0; index < आकार; index++) म_लिखो(out[index] < 32 ? "[%d]" : "%c", out[index]);
  म_लिखो(" (%d bytes)\n", आकार);
  वापस 0;
}
