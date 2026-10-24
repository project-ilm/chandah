#ضمن <stdio.h>
/* TCP congestion control: slow start, congestion avoidance, and a timeout at round 8 */
صحيح اصلي(فراغ) {
  صحيح کړکۍ = 1, پوله = 16;
  لكل (صحيح round = 1; round <= 12; round++) {
    چاپ_کړه("%d ", کړکۍ);
    إذا (round == 8) { پوله = کړکۍ / 2; کړکۍ = 1; }
    وإلا إذا (کړکۍ < پوله) کړکۍ *= 2;
    وإلا کړکۍ += 1;
  }
  چاپ_کړه("\n");
  أرجع 0;
}
