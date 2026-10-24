#समावेश <stdio.h>
/* structures, unions and sizeof */
काष्ठा point { पूर्णांक x, y; };
जोड़ number { पूर्णांक whole; अक्षर bytes[4]; };
पूर्णांक मुख्य(व्योम) {
  काष्ठा point corner = {3, 4};
  जोड़ number मान;
  मान.whole = 0x01020304;
  म_लिखो("%d %d %d\n", corner.x * corner.x + corner.y * corner.y, (पूर्णांक)माप(काष्ठा point), मान.bytes[0] == 4 || मान.bytes[0] == 1);
  वापस 0;
}
