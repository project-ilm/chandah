#شامل <stdio.h>
#شامل <pthread.h>
#شامل <semaphore.h>
/* concurrency: a bounded buffer of four slots between a producer and a consumer, with two semaphores and a mutex */
صحیح بفر[4], سر = 0, دم = 0;
طویل کل = 0;
sem_t خالی_خانے, بھرا;
pthread_mutex_t تالا = PTHREAD_MUTEX_INITIALIZER;
خالی *پیداکار(خالی *غیر_مستعمل) {
  برائے (صحیح قدر = 1; قدر <= 100; قدر++) {
    sem_wait(&خالی_خانے); pthread_mutex_lock(&تالا);
    بفر[دم] = قدر; دم = (دم + 1) % 4;
    pthread_mutex_unlock(&تالا); sem_post(&بھرا);
  }
  واپس غیر_مستعمل;
}
خالی *صارف(خالی *غیر_مستعمل) {
  برائے (صحیح گنتی = 0; گنتی < 100; گنتی++) {
    sem_wait(&بھرا); pthread_mutex_lock(&تالا);
    کل += بفر[سر]; سر = (سر + 1) % 4;
    pthread_mutex_unlock(&تالا); sem_post(&خالی_خانے);
  }
  واپس غیر_مستعمل;
}
صحیح مین(خالی) {
  pthread_t پہلا, دوسرا;
  sem_init(&خالی_خانے, 0, 4); sem_init(&بھرا, 0, 0);
  pthread_create(&پہلا, تہی, پیداکار, تہی); pthread_create(&دوسرا, تہی, صارف, تہی);
  pthread_join(پہلا, تہی); pthread_join(دوسرا, تہی);
  لکھو("%ld\n", کل);
  واپس 0;
}
