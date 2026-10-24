#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <unistd.h>
#ಅನ್ತರ್ಭಾವ <sys/wait.h>
/* processes: fork a child that sums 1..10 and returns it as its exit status; the parent waits for it */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  pid_t ಮಗು = fork();
  ಆದರೆ (ಮಗು == 0) { ಪೂರ್ಣಾಂಕ ಮೊತ್ತ = 0; ಗಾಗಿ (ಪೂರ್ಣಾಂಕ ಸಂಖ್ಯೆ = 1; ಸಂಖ್ಯೆ <= 10; ಸಂಖ್ಯೆ++) ಮೊತ್ತ += ಸಂಖ್ಯೆ; ನಿರ್ಗಮಿಸು(ಮೊತ್ತ); }
  ಪೂರ್ಣಾಂಕ ಸ್ಥಿತಿ_2;
  waitpid(ಮಗು, &ಸ್ಥಿತಿ_2, 0);
  ಬರೆ("child returned %d\n", WEXITSTATUS(ಸ್ಥಿತಿ_2));
  ಹಿಂತಿರುಗಿ 0;
}
