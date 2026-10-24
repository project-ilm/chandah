#ضمن <stdio.h>
#ضمن <stdlib.h>
#ضمن <unistd.h>
#ضمن <sys/wait.h>
/* processes: fork a child that sums 1..10 and returns it as its exit status; the parent waits for it */
صحيح اصلي(فراغ) {
  pid_t ماشوم = fork();
  إذا (ماشوم == 0) { صحيح مجموعه = 0; لكل (صحيح شمېره = 1; شمېره <= 10; شمېره++) مجموعه += شمېره; وتل(مجموعه); }
  صحيح حالت;
  waitpid(ماشوم, &حالت, 0);
  چاپ_کړه("child returned %d\n", WEXITSTATUS(حالت));
  أرجع 0;
}
