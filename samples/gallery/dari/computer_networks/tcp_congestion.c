#ضمن <stdio.h>
/* TCP congestion control: slow start, congestion avoidance, and a timeout at round 8 */
صحيح اصلی(فراغ) {
  صحيح پنجره = 1, آستانه = 16;
  لكل (صحيح round = 1; round <= 12; round++) {
    چاپ_کن("%d ", پنجره);
    إذا (round == 8) { آستانه = پنجره / 2; پنجره = 1; }
    وإلا إذا (پنجره < آستانه) پنجره *= 2;
    وإلا پنجره += 1;
  }
  چاپ_کن("\n");
  أرجع 0;
}
