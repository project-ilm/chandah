#ضمن <stdio.h>
#ضمن <stdlib.h>
#ضمن <unistd.h>
#ضمن <sys/wait.h>
/* processes: fork a child that sums 1..10 and returns it as its exit status; the parent waits for it */
صحيح مکيه(فراغ) {
  pid_t ٻار = fork();
  إذا (ٻار == 0) { صحيح جوڙ = 0; لكل (صحيح نمبر = 1; نمبر <= 10; نمبر++) جوڙ += نمبر; ٻاهر_نڪرو(جوڙ); }
  صحيح حالت;
  waitpid(ٻار, &حالت, 0);
  لکو("child returned %d\n", WEXITSTATUS(حالت));
  أرجع 0;
}
