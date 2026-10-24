#ضمن <stdio.h>
#ضمن <string.h>
/* DNS: a domain name in the wire format of a query, each label preceded by its length, ending with zero */
صحيح اصلی(فراغ) {
  ثابت حرف *متن = "www.example.com";
  بیعلامت حرف بیرون[64]; صحيح اندازه = 0, شروع = 0;
  لكل (صحيح index = 0; ; index++)
    إذا (متن[index] == '.' || متن[index] == '\0') {
      بیرون[اندازه++] = index - شروع;
      کپی_حافظه(بیرون + اندازه, متن + شروع, index - شروع); اندازه += index - شروع;
      شروع = index + 1;
      إذا (متن[index] == '\0') اكسر;
    }
  بیرون[اندازه++] = 0;
  لكل (صحيح index = 0; index < اندازه; index++) چاپ_کن(بیرون[index] < 32 ? "[%d]" : "%c", بیرون[index]);
  چاپ_کن(" (%d bytes)\n", اندازه);
  أرجع 0;
}
