#समावेश <stdio.h>
/* hash table with linear probing */
पूर्णांक keys[11], used[11];
पूर्णांक slot_of(पूर्णांक कुंजी) { पूर्णांक slot = कुंजी % 11; जबतक (used[slot] && keys[slot] != कुंजी) slot = (slot + 1) % 11; वापस slot; }
व्योम insert(पूर्णांक कुंजी) { पूर्णांक slot = slot_of(कुंजी); keys[slot] = कुंजी; used[slot] = 1; }
पूर्णांक contains(पूर्णांक कुंजी) { वापस used[slot_of(कुंजी)]; }
पूर्णांक मुख्य(व्योम) {
  पूर्णांक values[] = {22, 1, 13, 11, 24, 33, 18, 42, 31};
  क्रम (पूर्णांक index = 0; index < 9; index++) insert(values[index]);
  क्रम (पूर्णांक slot = 0; slot < 11; slot++) म_लिखो("%d ", used[slot] ? keys[slot] : -1);
  म_लिखो("\n%d %d\n", contains(42), contains(5));
  वापस 0;
}
