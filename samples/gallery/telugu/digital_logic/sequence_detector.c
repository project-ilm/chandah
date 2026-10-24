#అన్తర్భావ <stdio.h>
/* sequential circuits: a Moore state machine that detects 101 in a bit stream, overlaps allowed */
పూర్ణాంకం ప్రధాన(శూన్య) {
  పూర్ణాంకం తదుపరి[4][2] = {{0, 1}, {2, 1}, {0, 3}, {2, 1}};      /* states: none, seen 1, seen 10, seen 101 */
  స్థిరరాశి అక్షరం *ప్రవాహం = "1101011010";
  పూర్ణాంకం state = 0;
  కొరకు (పూర్ణాంకం index = 0; ప్రవాహం[index]; index++) {
    state = తదుపరి[state][ప్రవాహం[index] - '0'];
    రాయి("%d", state == 3);
  }
  రాయి("\n");
  తిరిగి 0;
}
