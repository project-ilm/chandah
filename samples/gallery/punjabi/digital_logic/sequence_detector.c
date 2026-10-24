#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* sequential circuits: a Moore state machine that detects 101 in a bit stream, overlaps allowed */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਪੂਰਨ ਅਗਲਾ[4][2] = {{0, 1}, {2, 1}, {0, 3}, {2, 1}};      /* states: none, seen 1, seen 10, seen 101 */
  ਅਚਲ ਅੱਖਰ *ਧਾਰਾ = "1101011010";
  ਪੂਰਨ state = 0;
  ਲਈ (ਪੂਰਨ index = 0; ਧਾਰਾ[index]; index++) {
    state = ਅਗਲਾ[state][ਧਾਰਾ[index] - '0'];
    ਲਿਖੋ("%d", state == 3);
  }
  ਲਿਖੋ("\n");
  ਵਾਪਸ 0;
}
