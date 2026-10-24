#ضمن <stdio.h>
#ضمن <string.h>
/* HTTP: read the request line and count the header lines of a request */
صحيح مکھ(فراغ) {
  حرف متن[] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\nAccept: text/html\r\nConnection: close\r\n\r\n";
  حرف طریقہ[16], رستہ[64], نسخہ[16];
  لڑی_توں_پڑھو(متن, "%15s %63s %15s", طریقہ, رستہ, نسخہ);
  صحيح سرخیاں = 0;
  لكل (حرف *سطر = لڑی_کھوج(متن, "\r\n") + 2; لڑی_مقابلہ(سطر, "\r\n", 2) != 0; سطر = لڑی_کھوج(سطر, "\r\n") + 2) سرخیاں++;
  لکھو("%s %s %s, %d headers\n", طریقہ, رستہ, نسخہ, سرخیاں);
  أرجع 0;
}
