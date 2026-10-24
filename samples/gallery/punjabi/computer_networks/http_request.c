#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
/* HTTP: read the request line and count the header lines of a request */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਅੱਖਰ ਪਾਠ[] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\nAccept: text/html\r\nConnection: close\r\n\r\n";
  ਅੱਖਰ ਵਿਧੀ[16], ਰਸਤਾ[64], ਸੰਸਕਰਣ[16];
  ਲੜੀ_ਤੋਂ_ਪੜ੍ਹੋ(ਪਾਠ, "%15s %63s %15s", ਵਿਧੀ, ਰਸਤਾ, ਸੰਸਕਰਣ);
  ਪੂਰਨ ਸਿਰਲੇਖਾਂ = 0;
  ਲਈ (ਅੱਖਰ *ਸਤਰ = ਲੜੀ_ਖੋਜ(ਪਾਠ, "\r\n") + 2; ਲੜੀ_ਤੁਲਨਾ(ਸਤਰ, "\r\n", 2) != 0; ਸਤਰ = ਲੜੀ_ਖੋਜ(ਸਤਰ, "\r\n") + 2) ਸਿਰਲੇਖਾਂ++;
  ਲਿਖੋ("%s %s %s, %d headers\n", ਵਿਧੀ, ਰਸਤਾ, ਸੰਸਕਰਣ, ਸਿਰਲੇਖਾਂ);
  ਵਾਪਸ 0;
}
