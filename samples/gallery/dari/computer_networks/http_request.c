#ضمن <stdio.h>
#ضمن <string.h>
/* HTTP: read the request line and count the header lines of a request */
صحيح اصلی(فراغ) {
  حرف متن[] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\nAccept: text/html\r\nConnection: close\r\n\r\n";
  حرف روش[16], مسیر[64], نسخه[16];
  از_رشته_بخوان(متن, "%15s %63s %15s", روش, مسیر, نسخه);
  صحيح سرآیندها = 0;
  لكل (حرف *سطر = جستجوی_رشته(متن, "\r\n") + 2; مقایسه_رشته(سطر, "\r\n", 2) != 0; سطر = جستجوی_رشته(سطر, "\r\n") + 2) سرآیندها++;
  چاپ_کن("%s %s %s, %d headers\n", روش, مسیر, نسخه, سرآیندها);
  أرجع 0;
}
