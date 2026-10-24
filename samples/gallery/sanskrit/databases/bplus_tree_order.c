#अन्तर्भाव <stdio.h>
/* indexing: the order of B+ tree nodes for a block size, and the levels needed for a million records */
पूर्णाङ्क मुख्यम्(शून्य) {
  पूर्णाङ्क खण्डम् = 512, कुञ्जी = 9, सूचकः = 6, लेखः_सूचकः = 7;
  पूर्णाङ्क आन्तरिकम् = (खण्डम् + कुञ्जी) / (कुञ्जी + सूचकः);                  /* p pointers and p - 1 keys fit in a block */
  पूर्णाङ्क पर्णम् = (खण्डम् - सूचकः) / (कुञ्जी + लेखः_सूचकः);             /* keys with record pointers, and one next-leaf pointer */
  दीर्घ लेखाः = 1000000, प्रापणम् = पर्णम्;
  पूर्णाङ्क स्तराः = 1;
  यावत् (प्रापणम् < लेखाः) { प्रापणम् *= आन्तरिकम्; स्तराः++; }
  प्रारूप_लिख("internal %d leaf %d levels %d\n", आन्तरिकम्, पर्णम्, स्तराः);
  प्रत्यागम 0;
}
