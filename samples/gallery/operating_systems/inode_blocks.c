#अन्तर्भाव <stdio.h>
/* file systems: the largest file an inode with 12 direct, one single, one double and one triple indirect pointer can map */
पूर्णाङ्क मुख्यम्(शून्य) {
  दीर्घ दीर्घ खण्डम् = 1024, सूचकाः = खण्डम् / 4;
  दीर्घ दीर्घ खण्डानि = 12 + सूचकाः + सूचकाः * सूचकाः + सूचकाः * सूचकाः * सूचकाः;
  प्रारूप_लिख("%lld blocks, %lld bytes\n", खण्डानि, खण्डानि * खण्डम्);
  प्रत्यागम 0;
}
