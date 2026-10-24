#شامل <stdio.h>
/* probability: Bayes' theorem for a test with known sensitivity and false-positive rate */
صحیح مین(خالی) {
  دوہرا پیشگی = 0.01, حساسیت = 0.95, جھوٹا_مثبت = 0.05;
  دوہرا شہادت = حساسیت * پیشگی + جھوٹا_مثبت * (1 - پیشگی);
  لکھو("%.4f\n", حساسیت * پیشگی / شہادت);
  واپس 0;
}
