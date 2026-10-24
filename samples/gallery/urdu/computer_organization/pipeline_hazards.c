#شامل <stdio.h>
/* instruction pipelining: a five-stage pipeline with forwarding stalls one cycle after each load whose result is used next */
صحیح مین(خالی) {
  صحیح بھرو[] = {1, 0, 1, 0, 0, 1, 0}, استعمال_کرتا_پچھلا[] = {0, 1, 0, 0, 1, 0, 1}, گنتی = 7, رکاوٹیں = 0;
  برائے (صحیح index = 1; index < گنتی; index++) اگر (بھرو[index - 1] && استعمال_کرتا_پچھلا[index]) رکاوٹیں++;
  لکھو("cycles %d stalls %d\n", 5 + (گنتی - 1) + رکاوٹیں, رکاوٹیں);
  واپس 0;
}
