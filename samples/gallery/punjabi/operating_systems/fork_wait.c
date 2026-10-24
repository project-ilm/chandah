#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <unistd.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/wait.h>
/* processes: fork a child that sums 1..10 and returns it as its exit status; the parent waits for it */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  pid_t ਬੱਚਾ = fork();
  ਜੇ (ਬੱਚਾ == 0) { ਪੂਰਨ ਜੋੜ = 0; ਲਈ (ਪੂਰਨ ਨੰਬਰ = 1; ਨੰਬਰ <= 10; ਨੰਬਰ++) ਜੋੜ += ਨੰਬਰ; ਬਾਹਰ_ਨਿਕਲੋ(ਜੋੜ); }
  ਪੂਰਨ ਸਥਿਤੀ;
  waitpid(ਬੱਚਾ, &ਸਥਿਤੀ, 0);
  ਲਿਖੋ("child returned %d\n", WEXITSTATUS(ਸਥਿਤੀ));
  ਵਾਪਸ 0;
}
