#شامل <stdio.h>
/* a DFA over binary strings that accepts multiples of three */
صحیح قبول_کرتا(ثابت حرف *لفظ) {
  صحیح state = 0;
  برائے (صحیح index = 0; لفظ[index]; index++) state = (state * 2 + (لفظ[index] - '0')) % 3;
  واپس state == 0;
}
صحیح مین(خالی) { لکھو("%d %d %d %d\n", قبول_کرتا("110"), قبول_کرتا("111"), قبول_کرتا("1001"), قبول_کرتا("0")); واپس 0; }
