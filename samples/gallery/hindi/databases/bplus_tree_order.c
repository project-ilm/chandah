#समावेश <stdio.h>
/* indexing: the order of B+ tree nodes for a block size, and the levels needed for a million records */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक block = 512, कुंजी = 9, pointer = 6, record_pointer = 7;
  पूर्णांक internal = (block + कुंजी) / (कुंजी + pointer);                  /* p pointers and p - 1 keys fit in a block */
  पूर्णांक leaf = (block - pointer) / (कुंजी + record_pointer);             /* keys with record pointers, and one next-leaf pointer */
  दीर्घ records = 1000000, reach = leaf;
  पूर्णांक levels = 1;
  जबतक (reach < records) { reach *= internal; levels++; }
  म_लिखो("internal %d leaf %d levels %d\n", internal, leaf, levels);
  वापस 0;
}
