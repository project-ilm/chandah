#ಅನ್ತರ್ಭಾವ <stdio.h>
/* file systems: the largest file an inode with 12 direct, one single, one double and one triple indirect pointer can map */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ದೀರ್ಘ ದೀರ್ಘ ಖಂಡ = 1024, ಸೂಚಕಗಳು = ಖಂಡ / 4;
  ದೀರ್ಘ ದೀರ್ಘ ಖಂಡಗಳು = 12 + ಸೂಚಕಗಳು + ಸೂಚಕಗಳು * ಸೂಚಕಗಳು + ಸೂಚಕಗಳು * ಸೂಚಕಗಳು * ಸೂಚಕಗಳು;
  ಬರೆ("%lld blocks, %lld bytes\n", ಖಂಡಗಳು, ಖಂಡಗಳು * ಖಂಡ);
  ಹಿಂತಿರುಗಿ 0;
}
