#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <ctype.h>
/* a hand-written lexer: identifiers, numbers and operators */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਅੱਖਰ ਸਰੋਤ[] = "total = count1 + 42 * rate;";
  ਪੂਰਨ index = 0, ਟੋਕਨ = 0;
  ਜਦੋਂ (ਸਰੋਤ[index]) {
    ਜੇ (ਖਾਲੀ_ਥਾਂ_ਹੈ(ਸਰੋਤ[index])) { index++; ਜਾਰੀ; }
    ਪੂਰਨ ਸ਼ੁਰੂ = index;
    ਜੇ (ਅੱਖਰ_ਹੈ(ਸਰੋਤ[index])) { ਜਦੋਂ (ਅੱਖਰ_ਜਾਂ_ਅੰਕ(ਸਰੋਤ[index])) index++; ਲਿਖੋ("ID "); }
    ਨਹੀਂਤਾਂ ਜੇ (ਅੰਕ_ਹੈ(ਸਰੋਤ[index])) { ਜਦੋਂ (ਅੰਕ_ਹੈ(ਸਰੋਤ[index])) index++; ਲਿਖੋ("NUM "); }
    ਨਹੀਂਤਾਂ { index++; ਲਿਖੋ("OP "); }
    ਟੋਕਨ++;
    (ਖਾਲੀ)ਸ਼ੁਰੂ;
  }
  ਲਿਖੋ("\n%d\n", ਟੋਕਨ);
  ਵਾਪਸ 0;
}
