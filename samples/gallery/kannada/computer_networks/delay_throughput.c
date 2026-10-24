#ಅನ್ತರ್ಭಾವ <stdio.h>
/* switching performance: transmission and propagation delay, and stop-and-wait link utilisation */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ದ್ವಿಗುಣ ಗಾತ್ರ_2 = 1000 * 8, ದರ = 1e6, ದೂರ = 2e6, ವೇಗ = 2e8;   /* bits, bits per second, metres, metres per second */
  ದ್ವಿಗುಣ ಸಂವಹನ = ಗಾತ್ರ_2 / ದರ, ಪ್ರಸರಣ = ದೂರ / ವೇಗ;
  ಬರೆ("%.1f ms %.1f ms %.2f\n", ಸಂವಹನ * 1000, ಪ್ರಸರಣ * 1000, ಸಂವಹನ / (ಸಂವಹನ + 2 * ಪ್ರಸರಣ));
  ಹಿಂತಿರುಗಿ 0;
}
