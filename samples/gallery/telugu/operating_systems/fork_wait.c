#అన్తర్భావ <stdio.h>
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <unistd.h>
#అన్తర్భావ <sys/wait.h>
/* processes: fork a child that sums 1..10 and returns it as its exit status; the parent waits for it */
పూర్ణాంకం ప్రధాన(శూన్య) {
  pid_t బిడ్డ = fork();
  ఒకవేళ (బిడ్డ == 0) { పూర్ణాంకం కూడిక = 0; కొరకు (పూర్ణాంకం సంఖ్య = 1; సంఖ్య <= 10; సంఖ్య++) కూడిక += సంఖ్య; నిష్క్రమించు(కూడిక); }
  పూర్ణాంకం స్థితి_2;
  waitpid(బిడ్డ, &స్థితి_2, 0);
  రాయి("child returned %d\n", WEXITSTATUS(స్థితి_2));
  తిరిగి 0;
}
