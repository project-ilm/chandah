#ضمن <stdio.h>
#ضمن <string.h>
/* DNS: a domain name in the wire format of a query, each label preceded by its length, ending with zero */
صحيح اصلي(فراغ) {
  ثابت حرف *متن = "www.example.com";
  بینښه حرف بهر[64]; صحيح اندازه = 0, پیل = 0;
  لكل (صحيح index = 0; ; index++)
    إذا (متن[index] == '.' || متن[index] == '\0') {
      بهر[اندازه++] = index - پیل;
      حافظه_نقل(بهر + اندازه, متن + پیل, index - پیل); اندازه += index - پیل;
      پیل = index + 1;
      إذا (متن[index] == '\0') اكسر;
    }
  بهر[اندازه++] = 0;
  لكل (صحيح index = 0; index < اندازه; index++) چاپ_کړه(بهر[index] < 32 ? "[%d]" : "%c", بهر[index]);
  چاپ_کړه(" (%d bytes)\n", اندازه);
  أرجع 0;
}
