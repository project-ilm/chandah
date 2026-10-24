#ضمن <stdio.h>
/* probability: Bayes' theorem for a test with known sensitivity and false-positive rate */
صحيح اصلی(فراغ) {
  مزدوج پیشین = 0.01, حساسیت = 0.95, مثبت_کاذب = 0.05;
  مزدوج شواهد = حساسیت * پیشین + مثبت_کاذب * (1 - پیشین);
  چاپ_کن("%.4f\n", حساسیت * پیشین / شواهد);
  أرجع 0;
}
