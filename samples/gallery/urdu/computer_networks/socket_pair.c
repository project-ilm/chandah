#شامل <stdio.h>
#شامل <ctype.h>
#شامل <stdlib.h>
#شامل <string.h>
#شامل <unistd.h>
#شامل <sys/socket.h>
#شامل <sys/wait.h>
/* the socket API: a connected pair of sockets; the child answers each message in capitals */
صحیح مین(خالی) {
  صحیح سرے[2];
  socketpair(AF_UNIX, SOCK_STREAM, 0, سرے);
  اگر (fork() == 0) {
    حرف متن[64]; ssize_t لمبائی = اقرأ(سرے[1], متن, حجم متن);
    برائے (ssize_t index = 0; index < لمبائی; index++) متن[index] = بڑا_حرف((غیرعلامتی حرف)متن[index]);
    باہر_نکلو(اكتب(سرے[1], متن, لمبائی) == لمبائی ? 0 : 1);
  }
  ثابت حرف *پیغام = "hello over a socket";
  حرف جواب[64] = {0};
  اگر (اكتب(سرے[0], پیغام, لڑی_لمبائی(پیغام)) < 0 || اقرأ(سرے[0], جواب, حجم جواب - 1) < 0) واپس 1;
  wait(تہی);
  لکھو("%s\n", جواب);
  واپس 0;
}
