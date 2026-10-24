#ضمن <stdio.h>
/* instruction pipelining: a five-stage pipeline with forwarding stalls one cycle after each load whose result is used next */
صحيح اصلی(فراغ) {
  صحيح بارگیری[] = {1, 0, 1, 0, 0, 1, 0}, استفاده_میکند_قبلی[] = {0, 1, 0, 0, 1, 0, 1}, شمار = 7, توقفها = 0;
  لكل (صحيح index = 1; index < شمار; index++) إذا (بارگیری[index - 1] && استفاده_میکند_قبلی[index]) توقفها++;
  چاپ_کن("cycles %d stalls %d\n", 5 + (شمار - 1) + توقفها, توقفها);
  أرجع 0;
}
