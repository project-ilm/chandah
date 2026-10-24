#అన్తర్భావ <stdio.h>
/* instruction pipelining: a five-stage pipeline with forwarding stalls one cycle after each load whose result is used next */
పూర్ణాంకం ప్రధాన(శూన్య) {
  పూర్ణాంకం ఎక్కించు[] = {1, 0, 1, 0, 0, 1, 0}, ఉపయోగిస్తుంది_మునుపటి[] = {0, 1, 0, 0, 1, 0, 1}, లెక్క = 7, నిలుపుదలలు = 0;
  కొరకు (పూర్ణాంకం index = 1; index < లెక్క; index++) ఒకవేళ (ఎక్కించు[index - 1] && ఉపయోగిస్తుంది_మునుపటి[index]) నిలుపుదలలు++;
  రాయి("cycles %d stalls %d\n", 5 + (లెక్క - 1) + నిలుపుదలలు, నిలుపుదలలు);
  తిరిగి 0;
}
