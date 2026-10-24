#ضمن <stdio.h>
/* an NFA, simulated on sets of states, accepting binary strings whose second-last symbol is 1 */
صحيح قبولي(ثابت حرف *لفظ) {
  صحيح حالتون = 1;                                /* bit k set means state k is active */
  لكل (صحيح index = 0; لفظ[index]; index++) {
    صحيح ايندڙ = 1;                                /* state 0 loops on both symbols */
    إذا (لفظ[index] == '1' && (حالتون & 1)) ايندڙ |= 2;
    إذا (حالتون & 2) ايندڙ |= 4;
    حالتون = ايندڙ;
  }
  أرجع (حالتون & 4) != 0;
}
صحيح مکيه(فراغ) { لکو("%d %d %d %d\n", قبولي("10"), قبولي("0110"), قبولي("011"), قبولي("1")); أرجع 0; }
