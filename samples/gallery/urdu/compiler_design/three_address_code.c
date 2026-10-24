#شامل <stdio.h>
/* intermediate code generation: three-address code for a = b * c + b * d, with common subexpression reuse shown */
صحیح مین(خالی) {
  ثابت حرف *رمز[] = {"t1 = b * c", "t2 = b * d", "t3 = t1 + t2", "a = t3"};
  برائے (صحیح index = 0; index < 4; index++) لکھو("%s\n", رمز[index]);
  واپس 0;
}
