#ضمن <stdio.h>
/* probability: Bayes' theorem for a test with known sensitivity and false-positive rate */
صحيح مکھ(فراغ) {
  مزدوج پہلوں = 0.01, حساسیت = 0.95, جھوٹا_مثبت = 0.05;
  مزدوج ثبوت = حساسیت * پہلوں + جھوٹا_مثبت * (1 - پہلوں);
  لکھو("%.4f\n", حساسیت * پہلوں / ثبوت);
  أرجع 0;
}
