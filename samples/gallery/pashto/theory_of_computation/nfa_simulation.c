#ضمن <stdio.h>
/* an NFA, simulated on sets of states, accepting binary strings whose second-last symbol is 1 */
صحيح مني(ثابت حرف *کلمه) {
  صحيح حالتونه = 1;                                /* bit k set means state k is active */
  لكل (صحيح index = 0; کلمه[index]; index++) {
    صحيح بل = 1;                                /* state 0 loops on both symbols */
    إذا (کلمه[index] == '1' && (حالتونه & 1)) بل |= 2;
    إذا (حالتونه & 2) بل |= 4;
    حالتونه = بل;
  }
  أرجع (حالتونه & 4) != 0;
}
صحيح اصلي(فراغ) { چاپ_کړه("%d %d %d %d\n", مني("10"), مني("0110"), مني("011"), مني("1")); أرجع 0; }
