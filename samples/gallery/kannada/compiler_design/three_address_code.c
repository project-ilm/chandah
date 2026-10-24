#ಅನ್ತರ್ಭಾವ <stdio.h>
/* intermediate code generation: three-address code for a = b * c + b * d, with common subexpression reuse shown */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂಕೇತ_2[] = {"t1 = b * c", "t2 = b * d", "t3 = t1 + t2", "a = t3"};
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ index = 0; index < 4; index++) ಬರೆ("%s\n", ಸಂಕೇತ_2[index]);
  ಹಿಂತಿರುಗಿ 0;
}
