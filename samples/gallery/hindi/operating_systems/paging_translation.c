#समावेश <stdio.h>
/* memory management: translate virtual addresses with a page table, page size 1024 */
पूर्णांक मुख्य(व्योम) {
  पूर्णांक table[8] = {5, 2, -1, 7, 1, -1, 3, 0}, addresses[] = {100, 2048, 3100, 7000, 5000};
  क्रम (पूर्णांक index = 0; index < 5; index++) {
    पूर्णांक page = addresses[index] / 1024, offset = addresses[index] % 1024;
    अगर (table[page] < 0) म_लिखो("fault ");
    अन्यथा म_लिखो("%d ", table[page] * 1024 + offset);
  }
  म_लिखो("\n");
  वापस 0;
}
