#شامل <stdio.h>
#شامل <string.h>
/* HTTP: read the request line and count the header lines of a request */
صحیح مین(خالی) {
  حرف متن[] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\nAccept: text/html\r\nConnection: close\r\n\r\n";
  حرف طریقہ[16], راستہ[64], نسخہ[16];
  لڑی_سے_پڑھو(متن, "%15s %63s %15s", طریقہ, راستہ, نسخہ);
  صحیح سرخیاں = 0;
  برائے (حرف *سطر = لڑی_تلاش(متن, "\r\n") + 2; لڑی_موازنہ(سطر, "\r\n", 2) != 0; سطر = لڑی_تلاش(سطر, "\r\n") + 2) سرخیاں++;
  لکھو("%s %s %s, %d headers\n", طریقہ, راستہ, نسخہ, سرخیاں);
  واپس 0;
}
