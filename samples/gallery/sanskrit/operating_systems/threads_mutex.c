#अन्तर्भाव <stdio.h>
#अन्तर्भाव <pthread.h>
/* threads and synchronisation: four threads add to one total, a mutex making each addition whole */
दीर्घ योगः = 0;
pthread_mutex_t तालकम् = PTHREAD_MUTEX_INITIALIZER;
शून्य *कार्यकर्ता(शून्य *अप्रयुक्तम्) {
  प्रति (पूर्णाङ्क सङ्ख्या = 1; सङ्ख्या <= 1000; सङ्ख्या++) { pthread_mutex_lock(&तालकम्); योगः += सङ्ख्या; pthread_mutex_unlock(&तालकम्); }
  प्रत्यागम अप्रयुक्तम्;
}
पूर्णाङ्क मुख्यम्(शून्य) {
  pthread_t तन्तवः[4];
  प्रति (पूर्णाङ्क index = 0; index < 4; index++) pthread_create(&तन्तवः[index], रिक्त, कार्यकर्ता, रिक्त);
  प्रति (पूर्णाङ्क index = 0; index < 4; index++) pthread_join(तन्तवः[index], रिक्त);
  प्रारूप_लिख("%ld\n", योगः);
  प्रत्यागम 0;
}
