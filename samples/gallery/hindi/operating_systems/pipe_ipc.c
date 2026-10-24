#समावेश <stdio.h>
#समावेश <stdlib.h>
#समावेश <unistd.h>
#समावेश <sys/wait.h>
/* inter-process communication: the parent sends numbers down one pipe, the child sends their sum back up another */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक down[2], up[2];
  अगर (pipe(down) != 0 || pipe(up) != 0) वापस 1;
  अगर (विभाजन() == 0) {
    पूर्णांक number, योग = 0;
    बंद(down[1]);
    जबतक (पढ़ो(down[0], &number, माप number) == माप number) योग += number;
    निकास(ग_लिखो(up[1], &योग, माप योग) == माप योग ? 0 : 1);
  }
  बंद(down[0]);
  क्रम (पूर्णांक number = 1; number <= 100; number++) अगर (ग_लिखो(down[1], &number, माप number) != माप number) वापस 1;
  बंद(down[1]);
  पूर्णांक योग;
  अगर (पढ़ो(up[0], &योग, माप योग) != माप योग) वापस 1;
  रुको(शून्य);
  म_लिखो("%d\n", योग);
  वापस 0;
}
