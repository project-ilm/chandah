#ضمن <stdio.h>
/* TCP congestion control: slow start, congestion avoidance, and a timeout at round 8 */
صحيح مکيه(فراغ) {
  صحيح دري = 1, حد = 16;
  لكل (صحيح round = 1; round <= 12; round++) {
    لکو("%d ", دري);
    إذا (round == 8) { حد = دري / 2; دري = 1; }
    وإلا إذا (دري < حد) دري *= 2;
    وإلا دري += 1;
  }
  لکو("\n");
  أرجع 0;
}
