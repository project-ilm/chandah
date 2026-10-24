#समावेश <stdio.h>
#समावेश <pthread.h>
#समावेश <semaphore.h>
/* concurrency: a bounded buffer of four slots between a producer and a consumer, with two semaphores and a mutex */
पूर्णांक बफर[4], शीर्ष = 0, पुच्छ = 0;
दीर्घ योग_2 = 0;
sem_t empty, full;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
व्योम *producer(व्योम *unused) {
  क्रम (पूर्णांक मान = 1; मान <= 100; मान++) {
    sem_wait(&empty); pthread_mutex_lock(&lock);
    बफर[पुच्छ] = मान; पुच्छ = (पुच्छ + 1) % 4;
    pthread_mutex_unlock(&lock); sem_post(&full);
  }
  वापस unused;
}
व्योम *consumer(व्योम *unused) {
  क्रम (पूर्णांक count = 0; count < 100; count++) {
    sem_wait(&full); pthread_mutex_lock(&lock);
    योग_2 += बफर[शीर्ष]; शीर्ष = (शीर्ष + 1) % 4;
    pthread_mutex_unlock(&lock); sem_post(&empty);
  }
  वापस unused;
}
पूर्णांक मुख्य(व्योम) {
  pthread_t first, second;
  sem_init(&empty, 0, 4); sem_init(&full, 0, 0);
  pthread_create(&first, शून्य, producer, शून्य); pthread_create(&second, शून्य, consumer, शून्य);
  pthread_join(first, शून्य); pthread_join(second, शून्य);
  म_लिखो("%ld\n", योग_2);
  वापस 0;
}
