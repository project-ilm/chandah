#समावेश <stdio.h>
/* binary min-heap as a priority queue */
पूर्णांक heap[32], आकार = 0;
व्योम insert(पूर्णांक मान) {
  पूर्णांक child = आकार++;
  heap[child] = मान;
  जबतक (child > 0 && heap[(child - 1) / 2] > heap[child]) { पूर्णांक parent = (child - 1) / 2, अस्थायी = heap[parent]; heap[parent] = heap[child]; heap[child] = अस्थायी; child = parent; }
}
पूर्णांक extract(व्योम) {
  पूर्णांक least = heap[0], parent = 0;
  heap[0] = heap[--आकार];
  क्रम (;;) {
    पूर्णांक smallest = parent, वाम = 2 * parent + 1, दक्षिण = वाम + 1;
    अगर (वाम < आकार && heap[वाम] < heap[smallest]) smallest = वाम;
    अगर (दक्षिण < आकार && heap[दक्षिण] < heap[smallest]) smallest = दक्षिण;
    अगर (smallest == parent) अवरोध;
    पूर्णांक अस्थायी = heap[parent]; heap[parent] = heap[smallest]; heap[smallest] = अस्थायी; parent = smallest;
  }
  वापस least;
}
पूर्णांक मुख्य(व्योम) {
  पूर्णांक values[] = {9, 4, 7, 1, 8, 2};
  क्रम (पूर्णांक index = 0; index < 6; index++) insert(values[index]);
  जबतक (आकार) म_लिखो("%d ", extract());
  म_लिखो("\n");
  वापस 0;
}
