#ضمن <stdio.h>
/* instruction pipelining: a five-stage pipeline with forwarding stalls one cycle after each load whose result is used next */
صحيح مکيه(فراغ) {
  صحيح ڀريو[] = {1, 0, 1, 0, 0, 1, 0}, استعمال_ڪري_اڳيون[] = {0, 1, 0, 0, 1, 0, 1}, ڳڻپ = 7, رڪاوٽون = 0;
  لكل (صحيح index = 1; index < ڳڻپ; index++) إذا (ڀريو[index - 1] && استعمال_ڪري_اڳيون[index]) رڪاوٽون++;
  لکو("cycles %d stalls %d\n", 5 + (ڳڻپ - 1) + رڪاوٽون, رڪاوٽون);
  أرجع 0;
}
