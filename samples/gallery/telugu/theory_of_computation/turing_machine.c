#అన్తర్భావ <stdio.h>
#అన్తర్భావ <string.h>
/* a Turing machine that adds one to a binary number written on its tape */
పూర్ణాంకం ప్రధాన(శూన్య) {
  అక్షరం పట్టీ[16] = "_1011_";
  పూర్ణాంకం తల = 4, state = 0, అడుగులు = 0;           /* state 0 carries, state 1 halts */
  అయితే (state == 0) {
    ఒకవేళ (పట్టీ[తల] == '1') { పట్టీ[తల] = '0'; తల--; }
    లేకపోతే { పట్టీ[తల] = '1'; state = 1; }
    అడుగులు++;
  }
  రాయి("%s %d\n", పట్టీ, అడుగులు);
  తిరిగి 0;
}
