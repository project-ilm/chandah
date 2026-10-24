#समावेश <stdio.h>
/* towers of Hanoi */
पूर्णांक moves = 0;
व्योम hanoi(पूर्णांक disks, अक्षर from, अक्षर to, अक्षर spare) {
  अगर (disks == 0) वापस;
  hanoi(disks - 1, from, spare, to);
  म_लिखो("%c>%c ", from, to); moves++;
  hanoi(disks - 1, spare, to, from);
}
पूर्णांक मुख्य(व्योम) { hanoi(3, 'A', 'C', 'B'); म_लिखो("\nmoves %d\n", moves); वापस 0; }
