#ضمن <stdio.h>
#ضمن <string.h>
/* DNS: a domain name in the wire format of a query, each label preceded by its length, ending with zero */
صحيح مکھ(فراغ) {
  ثابت حرف *متن = "www.example.com";
  بنانشانی حرف باہرلا[64]; صحيح ناپ = 0, شروع = 0;
  لكل (صحيح index = 0; ; index++)
    إذا (متن[index] == '.' || متن[index] == '\0') {
      باہرلا[ناپ++] = index - شروع;
      حافظہ_نقل(باہرلا + ناپ, متن + شروع, index - شروع); ناپ += index - شروع;
      شروع = index + 1;
      إذا (متن[index] == '\0') اكسر;
    }
  باہرلا[ناپ++] = 0;
  لكل (صحيح index = 0; index < ناپ; index++) لکھو(باہرلا[index] < 32 ? "[%d]" : "%c", باہرلا[index]);
  لکھو(" (%d bytes)\n", ناپ);
  أرجع 0;
}
