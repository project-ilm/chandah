#समावेश <stdio.h>
/* circular queue of size 4 */
पूर्णांक queue[4], शीर्ष = 0, count = 0;
पूर्णांक enqueue(पूर्णांक मान) { अगर (count == 4) वापस 0; queue[(शीर्ष + count++) % 4] = मान; वापस 1; }
पूर्णांक dequeue(व्योम) { पूर्णांक मान = queue[शीर्ष]; शीर्ष = (शीर्ष + 1) % 4; count--; वापस मान; }
पूर्णांक मुख्य(व्योम) {
  क्रम (पूर्णांक मान = 1; मान <= 5; मान++) म_लिखो("%d ", enqueue(मान * 10));
  पूर्णांक first = dequeue(), second = dequeue();
  म_लिखो("| %d %d | ", first, second);
  enqueue(60); enqueue(70);
  जबतक (count) म_लिखो("%d ", dequeue());
  म_लिखो("\n");
  वापस 0;
}
