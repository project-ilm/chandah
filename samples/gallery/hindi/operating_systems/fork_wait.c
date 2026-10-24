#समावेश <stdio.h>
#समावेश <stdlib.h>
#समावेश <unistd.h>
#समावेश <sys/wait.h>
/* processes: fork a child that sums 1..10 and returns it as its exit status; the parent waits for it */
पूर्णांक मुख्य(व्योम) {
  pid_t child = विभाजन();
  अगर (child == 0) { पूर्णांक योग = 0; क्रम (पूर्णांक number = 1; number <= 10; number++) योग += number; निकास(योग); }
  पूर्णांक status;
  waitpid(child, &status, 0);
  म_लिखो("child returned %d\n", WEXITSTATUS(status));
  वापस 0;
}
