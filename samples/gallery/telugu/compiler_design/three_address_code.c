#అన్తర్భావ <stdio.h>
/* intermediate code generation: three-address code for a = b * c + b * d, with common subexpression reuse shown */
పూర్ణాంకం ప్రధాన(శూన్య) {
  స్థిరరాశి అక్షరం *సంకేతం_2[] = {"t1 = b * c", "t2 = b * d", "t3 = t1 + t2", "a = t3"};
  కొరకు (పూర్ణాంకం index = 0; index < 4; index++) రాయి("%s\n", సంకేతం_2[index]);
  తిరిగి 0;
}
