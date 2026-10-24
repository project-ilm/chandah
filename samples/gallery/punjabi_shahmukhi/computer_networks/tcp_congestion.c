#ضمن <stdio.h>
/* TCP congestion control: slow start, congestion avoidance, and a timeout at round 8 */
صحيح مکھ(فراغ) {
  صحيح کھڑکی = 1, حد = 16;
  لكل (صحيح round = 1; round <= 12; round++) {
    لکھو("%d ", کھڑکی);
    إذا (round == 8) { حد = کھڑکی / 2; کھڑکی = 1; }
    وإلا إذا (کھڑکی < حد) کھڑکی *= 2;
    وإلا کھڑکی += 1;
  }
  لکھو("\n");
  أرجع 0;
}
