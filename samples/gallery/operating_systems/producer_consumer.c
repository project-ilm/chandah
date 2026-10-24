#अन्तर्भाव <stdio.h>
#अन्तर्भाव <pthread.h>
#अन्तर्भाव <semaphore.h>
/* concurrency: a bounded buffer of four slots between a producer and a consumer, with two semaphores and a mutex */
पूर्णाङ्क बफर[4], शिरः = 0, पुच्छम् = 0;
दीर्घ योगः = 0;
sem_t रिक्तानि, पूर्णम्;
pthread_mutex_t तालकम् = PTHREAD_MUTEX_INITIALIZER;
शून्य *उत्पादकः(शून्य *अप्रयुक्तम्) {
  प्रति (पूर्णाङ्क मूल्यम् = 1; मूल्यम् <= 100; मूल्यम्++) {
    sem_wait(&रिक्तानि); pthread_mutex_lock(&तालकम्);
    बफर[पुच्छम्] = मूल्यम्; पुच्छम् = (पुच्छम् + 1) % 4;
    pthread_mutex_unlock(&तालकम्); sem_post(&पूर्णम्);
  }
  प्रत्यागम अप्रयुक्तम्;
}
शून्य *उपभोक्ता(शून्य *अप्रयुक्तम्) {
  प्रति (पूर्णाङ्क गणना_2 = 0; गणना_2 < 100; गणना_2++) {
    sem_wait(&पूर्णम्); pthread_mutex_lock(&तालकम्);
    योगः += बफर[शिरः]; शिरः = (शिरः + 1) % 4;
    pthread_mutex_unlock(&तालकम्); sem_post(&रिक्तानि);
  }
  प्रत्यागम अप्रयुक्तम्;
}
पूर्णाङ्क मुख्यम्(शून्य) {
  pthread_t प्रथमम्, द्वितीयम्;
  sem_init(&रिक्तानि, 0, 4); sem_init(&पूर्णम्, 0, 0);
  pthread_create(&प्रथमम्, रिक्त, उत्पादकः, रिक्त); pthread_create(&द्वितीयम्, रिक्त, उपभोक्ता, रिक्त);
  pthread_join(प्रथमम्, रिक्त); pthread_join(द्वितीयम्, रिक्त);
  प्रारूप_लिख("%ld\n", योगः);
  प्रत्यागम 0;
}
