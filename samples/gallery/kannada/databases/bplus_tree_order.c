#ಅನ್ತರ್ಭಾವ <stdio.h>
/* indexing: the order of B+ tree nodes for a block size, and the levels needed for a million records */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ಪೂರ್ಣಾಂಕ ಖಂಡ = 512, ಕೀಲಿ = 9, ಸೂಚಕ = 6, ದಾಖಲೆ_ಸೂಚಕ = 7;
  ಪೂರ್ಣಾಂಕ ಆಂತರಿಕ = (ಖಂಡ + ಕೀಲಿ) / (ಕೀಲಿ + ಸೂಚಕ);                  /* p pointers and p - 1 keys fit in a block */
  ಪೂರ್ಣಾಂಕ ಎಲೆ = (ಖಂಡ - ಸೂಚಕ) / (ಕೀಲಿ + ದಾಖಲೆ_ಸೂಚಕ);             /* keys with record pointers, and one next-leaf pointer */
  ದೀರ್ಘ ದಾಖಲೆಗಳು = 1000000, ವ್ಯಾಪ್ತಿ = ಎಲೆ;
  ಪೂರ್ಣಾಂಕ ಮಟ್ಟಗಳು = 1;
  ಆಗ (ವ್ಯಾಪ್ತಿ < ದಾಖಲೆಗಳು) { ವ್ಯಾಪ್ತಿ *= ಆಂತರಿಕ; ಮಟ್ಟಗಳು++; }
  ಬರೆ("internal %d leaf %d levels %d\n", ಆಂತರಿಕ, ಎಲೆ, ಮಟ್ಟಗಳು);
  ಹಿಂತಿರುಗಿ 0;
}
