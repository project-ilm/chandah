#అన్తర్భావ <stdio.h>
#అన్తర్భావ <pthread.h>
#అన్తర్భావ <semaphore.h>
/* concurrency: a bounded buffer of four slots between a producer and a consumer, with two semaphores and a mutex */
పూర్ణాంకం బఫరు[4], తల = 0, తోక = 0;
దీర్ఘ మొత్తం = 0;
sem_t ఖాళీలు, నిండిన;
pthread_mutex_t తాళం = PTHREAD_MUTEX_INITIALIZER;
శూన్య *ఉత్పాదకుడు(శూన్య *వాడని) {
  కొరకు (పూర్ణాంకం విలువ = 1; విలువ <= 100; విలువ++) {
    sem_wait(&ఖాళీలు); pthread_mutex_lock(&తాళం);
    బఫరు[తోక] = విలువ; తోక = (తోక + 1) % 4;
    pthread_mutex_unlock(&తాళం); sem_post(&నిండిన);
  }
  తిరిగి వాడని;
}
శూన్య *వినియోగదారు(శూన్య *వాడని) {
  కొరకు (పూర్ణాంకం లెక్క = 0; లెక్క < 100; లెక్క++) {
    sem_wait(&నిండిన); pthread_mutex_lock(&తాళం);
    మొత్తం += బఫరు[తల]; తల = (తల + 1) % 4;
    pthread_mutex_unlock(&తాళం); sem_post(&ఖాళీలు);
  }
  తిరిగి వాడని;
}
పూర్ణాంకం ప్రధాన(శూన్య) {
  pthread_t మొదటి, రెండవ;
  sem_init(&ఖాళీలు, 0, 4); sem_init(&నిండిన, 0, 0);
  pthread_create(&మొదటి, ఖాళీ, ఉత్పాదకుడు, ఖాళీ); pthread_create(&రెండవ, ఖాళీ, వినియోగదారు, ఖాళీ);
  pthread_join(మొదటి, ఖాళీ); pthread_join(రెండవ, ఖాళీ);
  రాయి("%ld\n", మొత్తం);
  తిరిగి 0;
}
