#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <sys/wait.h>
/* processes: fork a child that sums 1..10 and returns it as its exit status; the parent waits for it */
पूर्णाङ्क मुख्यम्(शून्य) {
  pid_t सन्तानः = fork();
  यदि (सन्तानः == 0) { पूर्णाङ्क योगफलम् = 0; प्रति (पूर्णाङ्क सङ्ख्या = 1; सङ्ख्या <= 10; सङ्ख्या++) योगफलम् += सङ्ख्या; निर्गच्छ(योगफलम्); }
  पूर्णाङ्क स्थितिः;
  waitpid(सन्तानः, &स्थितिः, 0);
  प्रारूप_लिख("child returned %d\n", WEXITSTATUS(स्थितिः));
  प्रत्यागम 0;
}
