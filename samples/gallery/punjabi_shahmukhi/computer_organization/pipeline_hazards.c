#ضمن <stdio.h>
/* instruction pipelining: a five-stage pipeline with forwarding stalls one cycle after each load whose result is used next */
صحيح مکھ(فراغ) {
  صحيح لدو[] = {1, 0, 1, 0, 0, 1, 0}, ورتدا_پچھلا[] = {0, 1, 0, 0, 1, 0, 1}, گنتی = 7, رکاوٹاں = 0;
  لكل (صحيح index = 1; index < گنتی; index++) إذا (لدو[index - 1] && ورتدا_پچھلا[index]) رکاوٹاں++;
  لکھو("cycles %d stalls %d\n", 5 + (گنتی - 1) + رکاوٹاں, رکاوٹاں);
  أرجع 0;
}
