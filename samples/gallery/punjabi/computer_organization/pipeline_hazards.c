#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* instruction pipelining: a five-stage pipeline with forwarding stalls one cycle after each load whose result is used next */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਪੂਰਨ ਲੱਦੋ[] = {1, 0, 1, 0, 0, 1, 0}, ਵਰਤਦਾ_ਪਿਛਲਾ[] = {0, 1, 0, 0, 1, 0, 1}, ਗਿਣਤੀ_2 = 7, ਰੁਕਾਵਟਾਂ = 0;
  ਲਈ (ਪੂਰਨ index = 1; index < ਗਿਣਤੀ_2; index++) ਜੇ (ਲੱਦੋ[index - 1] && ਵਰਤਦਾ_ਪਿਛਲਾ[index]) ਰੁਕਾਵਟਾਂ++;
  ਲਿਖੋ("cycles %d stalls %d\n", 5 + (ਗਿਣਤੀ_2 - 1) + ਰੁਕਾਵਟਾਂ, ਰੁਕਾਵਟਾਂ);
  ਵਾਪਸ 0;
}
