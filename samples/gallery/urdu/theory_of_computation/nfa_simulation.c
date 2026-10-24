#شامل <stdio.h>
/* an NFA, simulated on sets of states, accepting binary strings whose second-last symbol is 1 */
صحیح قبول_کرتا(ثابت حرف *لفظ) {
  صحیح حالتیں = 1;                                /* bit k set means state k is active */
  برائے (صحیح index = 0; لفظ[index]; index++) {
    صحیح اگلا = 1;                                /* state 0 loops on both symbols */
    اگر (لفظ[index] == '1' && (حالتیں & 1)) اگلا |= 2;
    اگر (حالتیں & 2) اگلا |= 4;
    حالتیں = اگلا;
  }
  واپس (حالتیں & 4) != 0;
}
صحیح مین(خالی) { لکھو("%d %d %d %d\n", قبول_کرتا("10"), قبول_کرتا("0110"), قبول_کرتا("011"), قبول_کرتا("1")); واپس 0; }
