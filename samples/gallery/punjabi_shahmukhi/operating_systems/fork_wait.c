#ضمن <stdio.h>
#ضمن <stdlib.h>
#ضمن <unistd.h>
#ضمن <sys/wait.h>
/* processes: fork a child that sums 1..10 and returns it as its exit status; the parent waits for it */
صحيح مکھ(فراغ) {
  pid_t بچہ = fork();
  إذا (بچہ == 0) { صحيح جوڑ = 0; لكل (صحيح نمبر = 1; نمبر <= 10; نمبر++) جوڑ += نمبر; باہر_نکلو(جوڑ); }
  صحيح حالت;
  waitpid(بچہ, &حالت, 0);
  لکھو("child returned %d\n", WEXITSTATUS(حالت));
  أرجع 0;
}
