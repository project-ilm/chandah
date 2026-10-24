#شامل <stdio.h>
/* TCP congestion control: slow start, congestion avoidance, and a timeout at round 8 */
صحیح مین(خالی) {
  صحیح کھڑکی = 1, حد = 16;
  برائے (صحیح round = 1; round <= 12; round++) {
    لکھو("%d ", کھڑکی);
    اگر (round == 8) { حد = کھڑکی / 2; کھڑکی = 1; }
    ورنہ اگر (کھڑکی < حد) کھڑکی *= 2;
    ورنہ کھڑکی += 1;
  }
  لکھو("\n");
  واپس 0;
}
