#شامل <stdio.h>
#شامل <stdlib.h>
#شامل <unistd.h>
#شامل <sys/wait.h>
/* processes: fork a child that sums 1..10 and returns it as its exit status; the parent waits for it */
صحیح مین(خالی) {
  pid_t بچہ = fork();
  اگر (بچہ == 0) { صحیح مجموع = 0; برائے (صحیح نمبر = 1; نمبر <= 10; نمبر++) مجموع += نمبر; باہر_نکلو(مجموع); }
  صحیح حالت_2;
  waitpid(بچہ, &حالت_2, 0);
  لکھو("child returned %d\n", WEXITSTATUS(حالت_2));
  واپس 0;
}
