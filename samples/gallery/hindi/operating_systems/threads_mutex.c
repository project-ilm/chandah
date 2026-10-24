#समावेश <stdio.h>
#समावेश <pthread.h>
/* threads and synchronisation: four threads add to one total, a mutex making each addition whole */
दीर्घ योग_2 = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
व्योम *worker(व्योम *unused) {
  क्रम (पूर्णांक number = 1; number <= 1000; number++) { pthread_mutex_lock(&lock); योग_2 += number; pthread_mutex_unlock(&lock); }
  वापस unused;
}
पूर्णांक मुख्य(व्योम) {
  pthread_t threads[4];
  क्रम (पूर्णांक index = 0; index < 4; index++) pthread_create(&threads[index], शून्य, worker, शून्य);
  क्रम (पूर्णांक index = 0; index < 4; index++) pthread_join(threads[index], शून्य);
  म_लिखो("%ld\n", योग_2);
  वापस 0;
}
