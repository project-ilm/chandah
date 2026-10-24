#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* an NFA, simulated on sets of states, accepting binary strings whose second-last symbol is 1 */
ਪੂਰਨ ਮੰਨਦਾ(ਅਚਲ ਅੱਖਰ *ਸ਼ਬਦ) {
  ਪੂਰਨ ਹਾਲਤਾਂ = 1;                                /* bit k set means state k is active */
  ਲਈ (ਪੂਰਨ index = 0; ਸ਼ਬਦ[index]; index++) {
    ਪੂਰਨ ਅਗਲਾ = 1;                                /* state 0 loops on both symbols */
    ਜੇ (ਸ਼ਬਦ[index] == '1' && (ਹਾਲਤਾਂ & 1)) ਅਗਲਾ |= 2;
    ਜੇ (ਹਾਲਤਾਂ & 2) ਅਗਲਾ |= 4;
    ਹਾਲਤਾਂ = ਅਗਲਾ;
  }
  ਵਾਪਸ (ਹਾਲਤਾਂ & 4) != 0;
}
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) { ਲਿਖੋ("%d %d %d %d\n", ਮੰਨਦਾ("10"), ਮੰਨਦਾ("0110"), ਮੰਨਦਾ("011"), ਮੰਨਦਾ("1")); ਵਾਪਸ 0; }
