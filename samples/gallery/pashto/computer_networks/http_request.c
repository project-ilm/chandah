#ضمن <stdio.h>
#ضمن <string.h>
/* HTTP: read the request line and count the header lines of a request */
صحيح اصلي(فراغ) {
  حرف متن[] = "GET /index.html HTTP/1.1\r\nHost: example.com\r\nAccept: text/html\r\nConnection: close\r\n\r\n";
  حرف لاره[16], لار[64], نسخه[16];
  له_مزي_ولوله(متن, "%15s %63s %15s", لاره, لار, نسخه);
  صحيح سرلیکونه = 0;
  لكل (حرف *کرښه = مزي_پلټنه(متن, "\r\n") + 2; مزي_پرتله(کرښه, "\r\n", 2) != 0; کرښه = مزي_پلټنه(کرښه, "\r\n") + 2) سرلیکونه++;
  چاپ_کړه("%s %s %s, %d headers\n", لاره, لار, نسخه, سرلیکونه);
  أرجع 0;
}
