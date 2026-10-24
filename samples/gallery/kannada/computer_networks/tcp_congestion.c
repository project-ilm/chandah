#ಅನ್ತರ್ಭಾವ <stdio.h>
/* TCP congestion control: slow start, congestion avoidance, and a timeout at round 8 */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ಪೂರ್ಣಾಂಕ ಕಿಟಕಿ = 1, ಮಿತಿ = 16;
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ round = 1; round <= 12; round++) {
    ಬರೆ("%d ", ಕಿಟಕಿ);
    ಆದರೆ (round == 8) { ಮಿತಿ = ಕಿಟಕಿ / 2; ಕಿಟಕಿ = 1; }
    ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (ಕಿಟಕಿ < ಮಿತಿ) ಕಿಟಕಿ *= 2;
    ಇಲ್ಲದಿದ್ದರೆ ಕಿಟಕಿ += 1;
  }
  ಬರೆ("\n");
  ಹಿಂತಿರುಗಿ 0;
}
