#ಅನ್ತರ್ಭಾವ <stdio.h>
/* instruction pipelining: a five-stage pipeline with forwarding stalls one cycle after each load whose result is used next */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ಪೂರ್ಣಾಂಕ ತುಂಬು[] = {1, 0, 1, 0, 0, 1, 0}, ಬಳಸುತ್ತದೆ_ಹಿಂದಿನ[] = {0, 1, 0, 0, 1, 0, 1}, ಎಣಿಕೆ_2 = 7, ತಡೆಗಳು = 0;
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ index = 1; index < ಎಣಿಕೆ_2; index++) ಆದರೆ (ತುಂಬು[index - 1] && ಬಳಸುತ್ತದೆ_ಹಿಂದಿನ[index]) ತಡೆಗಳು++;
  ಬರೆ("cycles %d stalls %d\n", 5 + (ಎಣಿಕೆ_2 - 1) + ತಡೆಗಳು, ತಡೆಗಳು);
  ಹಿಂತಿರುಗಿ 0;
}
