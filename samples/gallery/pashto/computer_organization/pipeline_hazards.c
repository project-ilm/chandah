#ضمن <stdio.h>
/* instruction pipelining: a five-stage pipeline with forwarding stalls one cycle after each load whose result is used next */
صحيح اصلي(فراغ) {
  صحيح بارول[] = {1, 0, 1, 0, 0, 1, 0}, کاروي_پخوانی[] = {0, 1, 0, 0, 1, 0, 1}, شمېر = 7, ځنډونه = 0;
  لكل (صحيح index = 1; index < شمېر; index++) إذا (بارول[index - 1] && کاروي_پخوانی[index]) ځنډونه++;
  چاپ_کړه("cycles %d stalls %d\n", 5 + (شمېر - 1) + ځنډونه, ځنډونه);
  أرجع 0;
}
