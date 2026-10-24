#ضمن <stdio.h>
/* an NFA, simulated on sets of states, accepting binary strings whose second-last symbol is 1 */
صحيح میپذیرد(ثابت حرف *کلمه) {
  صحيح حالتها = 1;                                /* bit k set means state k is active */
  لكل (صحيح index = 0; کلمه[index]; index++) {
    صحيح بعدی = 1;                                /* state 0 loops on both symbols */
    إذا (کلمه[index] == '1' && (حالتها & 1)) بعدی |= 2;
    إذا (حالتها & 2) بعدی |= 4;
    حالتها = بعدی;
  }
  أرجع (حالتها & 4) != 0;
}
صحيح اصلی(فراغ) { چاپ_کن("%d %d %d %d\n", میپذیرد("10"), میپذیرد("0110"), میپذیرد("011"), میپذیرد("1")); أرجع 0; }
