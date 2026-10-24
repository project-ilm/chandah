#ضمن <stdio.h>
#ضمن <ctype.h>
#ضمن <stdlib.h>
#ضمن <string.h>
#ضمن <unistd.h>
#ضمن <sys/socket.h>
#ضمن <sys/wait.h>
/* the socket API: a connected pair of sockets; the child answers each message in capitals */
صحيح اصلي(فراغ) {
  صحيح پایونه[2];
  socketpair(AF_UNIX, SOCK_STREAM, 0, پایونه);
  إذا (fork() == 0) {
    حرف متن[64]; ssize_t اوږدتیا = اقرأ(پایونه[1], متن, حجم متن);
    لكل (ssize_t index = 0; index < اوږدتیا; index++) متن[index] = لوی_توری((بینښه حرف)متن[index]);
    وتل(اكتب(پایونه[1], متن, اوږدتیا) == اوږدتیا ? 0 : 1);
  }
  ثابت حرف *پیغام = "hello over a socket";
  حرف ځواب[64] = {0};
  إذا (اكتب(پایونه[0], پیغام, مزي_اوږدوالی(پیغام)) < 0 || اقرأ(پایونه[0], ځواب, حجم ځواب - 1) < 0) أرجع 1;
  wait(عدم);
  چاپ_کړه("%s\n", ځواب);
  أرجع 0;
}
