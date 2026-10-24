#समावेश <stdio.h>
/* file systems: the largest file an inode with 12 direct, one single, one double and one triple indirect pointer can map */
पूर्णांक मुख्य(व्योम) {
  दीर्घ दीर्घ block = 1024, pointers = block / 4;
  दीर्घ दीर्घ blocks = 12 + pointers + pointers * pointers + pointers * pointers * pointers;
  म_लिखो("%lld blocks, %lld bytes\n", blocks, blocks * block);
  वापस 0;
}
