#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
/* DNS: a domain name in the wire format of a query, each label preceded by its length, ending with zero */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಪಠ್ಯ = "www.example.com";
  ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಹೊರಹೋಗು[64]; ಪೂರ್ಣಾಂಕ ಗಾತ್ರ_2 = 0, ಆರಂಭ = 0;
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ index = 0; ; index++)
    ಆದರೆ (ಪಠ್ಯ[index] == '.' || ಪಠ್ಯ[index] == '\0') {
      ಹೊರಹೋಗು[ಗಾತ್ರ_2++] = index - ಆರಂಭ;
      ಸ್ಮರಣೆ_ನಕಲು(ಹೊರಹೋಗು + ಗಾತ್ರ_2, ಪಠ್ಯ + ಆರಂಭ, index - ಆರಂಭ); ಗಾತ್ರ_2 += index - ಆರಂಭ;
      ಆರಂಭ = index + 1;
      ಆದರೆ (ಪಠ್ಯ[index] == '\0') ನಿಲ್ಲಿಸು;
    }
  ಹೊರಹೋಗು[ಗಾತ್ರ_2++] = 0;
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ index = 0; index < ಗಾತ್ರ_2; index++) ಬರೆ(ಹೊರಹೋಗು[index] < 32 ? "[%d]" : "%c", ಹೊರಹೋಗು[index]);
  ಬರೆ(" (%d bytes)\n", ಗಾತ್ರ_2);
  ಹಿಂತಿರುಗಿ 0;
}
