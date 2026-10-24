#ಅನ್ತರ್ಭಾವ <stdio.h>
/* sequential circuits: a Moore state machine that detects 101 in a bit stream, overlaps allowed */
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  ಪೂರ್ಣಾಂಕ ಮುಂದಿನ[4][2] = {{0, 1}, {2, 1}, {0, 3}, {2, 1}};      /* states: none, seen 1, seen 10, seen 101 */
  ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಹರಿವು = "1101011010";
  ಪೂರ್ಣಾಂಕ state = 0;
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ index = 0; ಹರಿವು[index]; index++) {
    state = ಮುಂದಿನ[state][ಹರಿವು[index] - '0'];
    ಬರೆ("%d", state == 3);
  }
  ಬರೆ("\n");
  ಹಿಂತಿರುಗಿ 0;
}
