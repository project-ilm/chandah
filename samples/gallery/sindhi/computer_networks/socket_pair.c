#ضمن <stdio.h>
#ضمن <ctype.h>
#ضمن <stdlib.h>
#ضمن <string.h>
#ضمن <unistd.h>
#ضمن <sys/socket.h>
#ضمن <sys/wait.h>
/* the socket API: a connected pair of sockets; the child answers each message in capitals */
صحيح مکيه(فراغ) {
  صحيح پڇاڙيون[2];
  socketpair(AF_UNIX, SOCK_STREAM, 0, پڇاڙيون);
  إذا (fork() == 0) {
    حرف متن[64]; ssize_t ڊيگهائي = اقرأ(پڇاڙيون[1], متن, حجم متن);
    لكل (ssize_t index = 0; index < ڊيگهائي; index++) متن[index] = وڏو_اکر((بنانشان حرف)متن[index]);
    ٻاهر_نڪرو(اكتب(پڇاڙيون[1], متن, ڊيگهائي) == ڊيگهائي ? 0 : 1);
  }
  ثابت حرف *پيغام = "hello over a socket";
  حرف جواب[64] = {0};
  إذا (اكتب(پڇاڙيون[0], پيغام, لڙي_ڊيگهه(پيغام)) < 0 || اقرأ(پڇاڙيون[0], جواب, حجم جواب - 1) < 0) أرجع 1;
  wait(عدم);
  لکو("%s\n", جواب);
  أرجع 0;
}
