#समावेश <stdio.h>
/* flow control: Go-Back-N with a window of 4; frame 5 is lost once, so the sender goes back to it */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक window = 4, base = 0, अग्र = 0, frames = 10, lost = 5, sent = 0;
  जबतक (base < frames) {
    जबतक (अग्र < base + window && अग्र < frames) { म_लिखो("%d ", अग्र); sent++; अग्र++; }
    अगर (lost >= base && lost < अग्र) { म_लिखो("| timeout %d | ", lost); अग्र = lost; base = lost; lost = -1; }
    अन्यथा base = अग्र;
  }
  म_लिखो("\nsent %d\n", sent);
  वापस 0;
}
