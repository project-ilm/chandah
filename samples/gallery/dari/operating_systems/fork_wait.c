#ضمن <stdio.h>
#ضمن <stdlib.h>
#ضمن <unistd.h>
#ضمن <sys/wait.h>
/* processes: fork a child that sums 1..10 and returns it as its exit status; the parent waits for it */
صحيح اصلی(فراغ) {
  pid_t فرزند = fork();
  إذا (فرزند == 0) { صحيح جمع = 0; لكل (صحيح شماره = 1; شماره <= 10; شماره++) جمع += شماره; خروج(جمع); }
  صحيح وضعیت;
  waitpid(فرزند, &وضعیت, 0);
  چاپ_کن("child returned %d\n", WEXITSTATUS(وضعیت));
  أرجع 0;
}
