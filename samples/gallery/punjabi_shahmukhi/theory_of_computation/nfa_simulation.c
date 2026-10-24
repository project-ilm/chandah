#ضمن <stdio.h>
/* an NFA, simulated on sets of states, accepting binary strings whose second-last symbol is 1 */
صحيح مندا(ثابت حرف *لفظ) {
  صحيح حالتاں = 1;                                /* bit k set means state k is active */
  لكل (صحيح index = 0; لفظ[index]; index++) {
    صحيح اگلا = 1;                                /* state 0 loops on both symbols */
    إذا (لفظ[index] == '1' && (حالتاں & 1)) اگلا |= 2;
    إذا (حالتاں & 2) اگلا |= 4;
    حالتاں = اگلا;
  }
  أرجع (حالتاں & 4) != 0;
}
صحيح مکھ(فراغ) { لکھو("%d %d %d %d\n", مندا("10"), مندا("0110"), مندا("011"), مندا("1")); أرجع 0; }
