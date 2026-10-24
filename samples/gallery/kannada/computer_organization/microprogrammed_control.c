#ಅನ್ತರ್ಭಾವ <stdio.h>
/* control unit design: a microprogrammed sequencer; each microinstruction names its control signals and the next one */
ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸಂಕೇತಗಳು[] = {"PC->MAR", "MEM->MDR PC+1", "MDR->IR", "dispatch", "IR->MAR", "MEM->MDR", "MDR+ACC->ACC", "MDR->ACC"};
ಪೂರ್ಣಾಂಕ ಮುಂದಿನ[] = {1, 2, 3, -1, 5, 6, 0, 0};
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ಪೂರ್ಣಾಂಕ ಆರಂಭ[2] = {4, 4}, ಮುಕ್ತಾಯ[2] = {6, 7};   /* ADD and LOAD share the operand fetch, then differ */
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ ಬಗೆ = 0; ಬಗೆ < 2; ಬಗೆ++) {
    ಪೂರ್ಣಾಂಕ ವಿಳಾಸ = 0;
    ಆಗ (ವಿಳಾಸ != -1) {
      ಬರೆ("%s; ", ಸಂಕೇತಗಳು[ವಿಳಾಸ]);
      ವಿಳಾಸ = ಮುಂದಿನ[ವಿಳಾಸ];
    }
    ಗಾಗಿ (ವಿಳಾಸ = ಆರಂಭ[ಬಗೆ]; ವಿಳಾಸ != 6; ವಿಳಾಸ = ಮುಂದಿನ[ವಿಳಾಸ]) ಬರೆ("%s; ", ಸಂಕೇತಗಳು[ವಿಳಾಸ]);
    ಬರೆ("%s\n", ಸಂಕೇತಗಳು[ಮುಕ್ತಾಯ[ಬಗೆ]]);
  }
  ಹಿಂತಿರುಗಿ 0;
}
