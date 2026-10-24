#ضمن <stdio.h>
#ضمن <ctype.h>
#ضمن <stdlib.h>
#ضمن <string.h>
#ضمن <unistd.h>
#ضمن <sys/socket.h>
#ضمن <sys/wait.h>
/* the socket API: a connected pair of sockets; the child answers each message in capitals */
صحيح اصلی(فراغ) {
  صحيح دوسر[2];
  socketpair(AF_UNIX, SOCK_STREAM, 0, دوسر);
  إذا (fork() == 0) {
    حرف متن[64]; ssize_t درازی = اقرأ(دوسر[1], متن, حجم متن);
    لكل (ssize_t index = 0; index < درازی; index++) متن[index] = به_بزرگ((بیعلامت حرف)متن[index]);
    خروج(اكتب(دوسر[1], متن, درازی) == درازی ? 0 : 1);
  }
  ثابت حرف *پیام = "hello over a socket";
  حرف پاسخ[64] = {0};
  إذا (اكتب(دوسر[0], پیام, طول_رشته(پیام)) < 0 || اقرأ(دوسر[0], پاسخ, حجم پاسخ - 1) < 0) أرجع 1;
  wait(عدم);
  چاپ_کن("%s\n", پاسخ);
  أرجع 0;
}
