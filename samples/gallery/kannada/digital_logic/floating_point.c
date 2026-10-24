#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
/* number representation: the sign, exponent and fraction of an IEEE 754 single-precision number */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ದಶಮಾಂಶ ಸಂಖ್ಯೆ = -6.25f;
  ಚಿಹ್ನೆರಹಿತ ಬಿಟ್ಟುಗಳು;
  ಸ್ಮರಣೆ_ನಕಲು(&ಬಿಟ್ಟುಗಳು, &ಸಂಖ್ಯೆ, ಗಾತ್ರ ಬಿಟ್ಟುಗಳು);
  ಬರೆ("sign %u exponent %u fraction %06X\n", ಬಿಟ್ಟುಗಳು >> 31, ((ಬಿಟ್ಟುಗಳು >> 23) & 0xFF) - 127, ಬಿಟ್ಟುಗಳು & 0x7FFFFF);
  ಹಿಂತಿರುಗಿ 0;
}
