#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
/* a Turing machine that adds one to a binary number written on its tape */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਅੱਖਰ ਫੀਤਾ[16] = "_1011_";
  ਪੂਰਨ ਸਿਰ = 4, state = 0, ਕਦਮਾਂ = 0;           /* state 0 carries, state 1 halts */
  ਜਦੋਂ (state == 0) {
    ਜੇ (ਫੀਤਾ[ਸਿਰ] == '1') { ਫੀਤਾ[ਸਿਰ] = '0'; ਸਿਰ--; }
    ਨਹੀਂਤਾਂ { ਫੀਤਾ[ਸਿਰ] = '1'; state = 1; }
    ਕਦਮਾਂ++;
  }
  ਲਿਖੋ("%s %d\n", ਫੀਤਾ, ਕਦਮਾਂ);
  ਵਾਪਸ 0;
}
