#समावेश <stdio.h>
/* instruction pipelining: a five-stage pipeline with forwarding stalls one cycle after each load whose result is used next */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक load[] = {1, 0, 1, 0, 0, 1, 0}, uses_previous[] = {0, 1, 0, 0, 1, 0, 1}, count = 7, stalls = 0;
  क्रम (पूर्णांक index = 1; index < count; index++) अगर (load[index - 1] && uses_previous[index]) stalls++;
  म_लिखो("cycles %d stalls %d\n", 5 + (count - 1) + stalls, stalls);
  वापस 0;
}
