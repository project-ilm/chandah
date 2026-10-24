#ضمن <stdio.h>
#ضمن <string.h>
/* HTTP: read the request line and count the header lines of a request */
صحيح مکيه(فراغ) {
  حرف متن[] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\nAccept: text/html\r\nConnection: close\r\n\r\n";
  حرف طريقو[16], رستو[64], نسخو[16];
  لڙي_مان_پڙهو(متن, "%15s %63s %15s", طريقو, رستو, نسخو);
  صحيح سرا = 0;
  لكل (حرف *سٽ = لڙي_ڳولا(متن, "\r\n") + 2; لڙي_ڀيٽ(سٽ, "\r\n", 2) != 0; سٽ = لڙي_ڳولا(سٽ, "\r\n") + 2) سرا++;
  لکو("%s %s %s, %d headers\n", طريقو, رستو, نسخو, سرا);
  أرجع 0;
}
