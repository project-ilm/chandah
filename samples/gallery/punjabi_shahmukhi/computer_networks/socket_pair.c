#ضمن <stdio.h>
#ضمن <ctype.h>
#ضمن <stdlib.h>
#ضمن <string.h>
#ضمن <unistd.h>
#ضمن <sys/socket.h>
#ضمن <sys/wait.h>
/* the socket API: a connected pair of sockets; the child answers each message in capitals */
صحيح مکھ(فراغ) {
  صحيح سرے[2];
  socketpair(AF_UNIX, SOCK_STREAM, 0, سرے);
  إذا (fork() == 0) {
    حرف متن[64]; ssize_t لمائی = اقرأ(سرے[1], متن, حجم متن);
    لكل (ssize_t index = 0; index < لمائی; index++) متن[index] = وڈا_حرف((بنانشانی حرف)متن[index]);
    باہر_نکلو(اكتب(سرے[1], متن, لمائی) == لمائی ? 0 : 1);
  }
  ثابت حرف *سنیہا = "hello over a socket";
  حرف جواب[64] = {0};
  إذا (اكتب(سرے[0], سنیہا, لڑی_لمبائی(سنیہا)) < 0 || اقرأ(سرے[0], جواب, حجم جواب - 1) < 0) أرجع 1;
  wait(عدم);
  لکھو("%s\n", جواب);
  أرجع 0;
}
