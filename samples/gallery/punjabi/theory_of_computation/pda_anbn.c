#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* pushdown automata: accept a^n b^n (n >= 1) with a stack, reading a's then b's */
ਪੂਰਨ ਮੰਨਦਾ(ਅਚਲ ਅੱਖਰ *ਸ਼ਬਦ) {
  ਅੱਖਰ ਥੱਬਾ[64]; ਪੂਰਨ ਸਿਖਰ = 0, state = 0, index = 0;           /* state 0 reads a's, state 1 reads b's */
  ਲਈ (; ਸ਼ਬਦ[index]; index++) {
    ਜੇ (state == 0 && ਸ਼ਬਦ[index] == 'a') ਥੱਬਾ[ਸਿਖਰ++] = 'A';
    ਨਹੀਂਤਾਂ ਜੇ (ਸ਼ਬਦ[index] == 'b' && ਸਿਖਰ > 0 && ਥੱਬਾ[ਸਿਖਰ - 1] == 'A') { state = 1; ਸਿਖਰ--; }
    ਨਹੀਂਤਾਂ ਵਾਪਸ 0;
  }
  ਵਾਪਸ state == 1 && ਸਿਖਰ == 0;
}
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) { ਲਿਖੋ("%d %d %d %d\n", ਮੰਨਦਾ("ab"), ਮੰਨਦਾ("aaabbb"), ਮੰਨਦਾ("aabbb"), ਮੰਨਦਾ("abab")); ਵਾਪਸ 0; }
