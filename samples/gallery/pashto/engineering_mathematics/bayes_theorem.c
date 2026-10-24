#ضمن <stdio.h>
/* probability: Bayes' theorem for a test with known sensitivity and false-positive rate */
صحيح اصلي(فراغ) {
  مزدوج مخکینی = 0.01, حساسیت = 0.95, دروغجن_مثبت = 0.05;
  مزدوج شواهد = حساسیت * مخکینی + دروغجن_مثبت * (1 - مخکینی);
  چاپ_کړه("%.4f\n", حساسیت * مخکینی / شواهد);
  أرجع 0;
}
