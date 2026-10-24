#समावेश <stdio.h>
#समावेश <ctype.h>
#समावेश <stdlib.h>
#समावेश <string.h>
#समावेश <unistd.h>
#समावेश <sys/socket.h>
#समावेश <sys/wait.h>
/* the socket API: a connected pair of sockets; the child answers each message in capitals */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक ends[2];
  socketpair(AF_UNIX, SOCK_STREAM, 0, ends);
  अगर (विभाजन() == 0) {
    अक्षर text[64]; ssize_t लंबाई = पढ़ो(ends[1], text, माप text);
    क्रम (ssize_t index = 0; index < लंबाई; index++) text[index] = बड़े((अचिन्हित अक्षर)text[index]);
    निकास(ग_लिखो(ends[1], text, लंबाई) == लंबाई ? 0 : 1);
  }
  स्थिर अक्षर *message = "hello over a socket";
  अक्षर reply[64] = {0};
  अगर (ग_लिखो(ends[0], message, म_माप(message)) < 0 || पढ़ो(ends[0], reply, माप reply - 1) < 0) वापस 1;
  रुको(शून्य);
  म_लिखो("%s\n", reply);
  वापस 0;
}
