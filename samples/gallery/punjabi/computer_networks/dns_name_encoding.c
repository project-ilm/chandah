#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
/* DNS: a domain name in the wire format of a query, each label preceded by its length, ending with zero */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਅਚਲ ਅੱਖਰ *ਪਾਠ = "www.example.com";
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਬਾਹਰਲਾ[64]; ਪੂਰਨ ਮਾਪ = 0, ਸ਼ੁਰੂ = 0;
  ਲਈ (ਪੂਰਨ index = 0; ; index++)
    ਜੇ (ਪਾਠ[index] == '.' || ਪਾਠ[index] == '\0') {
      ਬਾਹਰਲਾ[ਮਾਪ++] = index - ਸ਼ੁਰੂ;
      ਸਮ੍ਰਿਤੀ_ਨਕਲ(ਬਾਹਰਲਾ + ਮਾਪ, ਪਾਠ + ਸ਼ੁਰੂ, index - ਸ਼ੁਰੂ); ਮਾਪ += index - ਸ਼ੁਰੂ;
      ਸ਼ੁਰੂ = index + 1;
      ਜੇ (ਪਾਠ[index] == '\0') ਰੋਕੋ;
    }
  ਬਾਹਰਲਾ[ਮਾਪ++] = 0;
  ਲਈ (ਪੂਰਨ index = 0; index < ਮਾਪ; index++) ਲਿਖੋ(ਬਾਹਰਲਾ[index] < 32 ? "[%d]" : "%c", ਬਾਹਰਲਾ[index]);
  ਲਿਖੋ(" (%d bytes)\n", ਮਾਪ);
  ਵਾਪਸ 0;
}
