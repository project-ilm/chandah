#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
/* a Turing machine that adds one to a binary number written on its tape */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ಅಕ್ಷರ ಪಟ್ಟಿ[16] = "_1011_";
  ಪೂರ್ಣಾಂಕ ತಲೆ = 4, state = 0, ಹೆಜ್ಜೆಗಳು = 0;           /* state 0 carries, state 1 halts */
  ಆಗ (state == 0) {
    ಆದರೆ (ಪಟ್ಟಿ[ತಲೆ] == '1') { ಪಟ್ಟಿ[ತಲೆ] = '0'; ತಲೆ--; }
    ಇಲ್ಲದಿದ್ದರೆ { ಪಟ್ಟಿ[ತಲೆ] = '1'; state = 1; }
    ಹೆಜ್ಜೆಗಳು++;
  }
  ಬರೆ("%s %d\n", ಪಟ್ಟಿ, ಹೆಜ್ಜೆಗಳು);
  ಹಿಂತಿರುಗಿ 0;
}
