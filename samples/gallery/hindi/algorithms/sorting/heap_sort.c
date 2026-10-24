#समावेश <stdio.h>
/* heap sort with a max heap */
व्योम sift_down(पूर्णांक values[], पूर्णांक आकार, पूर्णांक मूल) {
  पूर्णांक largest = मूल, वाम = 2 * मूल + 1, दक्षिण = 2 * मूल + 2;
  अगर (वाम < आकार && values[वाम] > values[largest]) largest = वाम;
  अगर (दक्षिण < आकार && values[दक्षिण] > values[largest]) largest = दक्षिण;
  अगर (largest != मूल) { पूर्णांक अस्थायी = values[मूल]; values[मूल] = values[largest]; values[largest] = अस्थायी; sift_down(values, आकार, largest); }
}
पूर्णांक मुख्य(व्योम) {
  पूर्णांक values[] = {12, 11, 13, 5, 6, 7}, count = 6;
  क्रम (पूर्णांक मूल = count / 2 - 1; मूल >= 0; मूल--) sift_down(values, count, मूल);
  क्रम (पूर्णांक last = count - 1; last > 0; last--) {
    पूर्णांक अस्थायी = values[0]; values[0] = values[last]; values[last] = अस्थायी;
    sift_down(values, last, 0);
  }
  क्रम (पूर्णांक index = 0; index < count; index++) म_लिखो("%d ", values[index]);
  म_लिखो("\n");
  वापस 0;
}
