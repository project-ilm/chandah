#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* a DFA over binary strings that accepts multiples of three */
ਪੂਰਨ ਮੰਨਦਾ(ਅਚਲ ਅੱਖਰ *ਸ਼ਬਦ) {
  ਪੂਰਨ state = 0;
  ਲਈ (ਪੂਰਨ index = 0; ਸ਼ਬਦ[index]; index++) state = (state * 2 + (ਸ਼ਬਦ[index] - '0')) % 3;
  ਵਾਪਸ state == 0;
}
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) { ਲਿਖੋ("%d %d %d %d\n", ਮੰਨਦਾ("110"), ਮੰਨਦਾ("111"), ਮੰਨਦਾ("1001"), ਮੰਨਦਾ("0")); ਵਾਪਸ 0; }
