#ضمن <stdio.h>
/* probability: Bayes' theorem for a test with known sensitivity and false-positive rate */
صحيح مکيه(فراغ) {
  مزدوج اڳواٽ = 0.01, حساسيت = 0.95, ڪوڙو_مثبت = 0.05;
  مزدوج ثبوت = حساسيت * اڳواٽ + ڪوڙو_مثبت * (1 - اڳواٽ);
  لکو("%.4f\n", حساسيت * اڳواٽ / ثبوت);
  أرجع 0;
}
