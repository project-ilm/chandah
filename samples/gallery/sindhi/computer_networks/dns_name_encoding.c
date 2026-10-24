#ضمن <stdio.h>
#ضمن <string.h>
/* DNS: a domain name in the wire format of a query, each label preceded by its length, ending with zero */
صحيح مکيه(فراغ) {
  ثابت حرف *متن = "www.example.com";
  بنانشان حرف ٻاهريون[64]; صحيح سائيز = 0, شروعات = 0;
  لكل (صحيح index = 0; ; index++)
    إذا (متن[index] == '.' || متن[index] == '\0') {
      ٻاهريون[سائيز++] = index - شروعات;
      يادگيري_نقل(ٻاهريون + سائيز, متن + شروعات, index - شروعات); سائيز += index - شروعات;
      شروعات = index + 1;
      إذا (متن[index] == '\0') اكسر;
    }
  ٻاهريون[سائيز++] = 0;
  لكل (صحيح index = 0; index < سائيز; index++) لکو(ٻاهريون[index] < 32 ? "[%d]" : "%c", ٻاهريون[index]);
  لکو(" (%d bytes)\n", سائيز);
  أرجع 0;
}
