#ضمن <stdio.h>
#ضمن <pthread.h>
#ضمن <semaphore.h>
/* concurrency: a bounded buffer of four slots between a producer and a consumer, with two semaphores and a mutex */
صحيح بفر[4], سر = 0, پوچھ = 0;
لما کل = 0;
sem_t خالی_تھاواں, بھریا;
pthread_mutex_t جندرا = PTHREAD_MUTEX_INITIALIZER;
فراغ *پیداکار(فراغ *بن_ورتیا) {
  لكل (صحيح قیمت = 1; قیمت <= 100; قیمت++) {
    sem_wait(&خالی_تھاواں); pthread_mutex_lock(&جندرا);
    بفر[پوچھ] = قیمت; پوچھ = (پوچھ + 1) % 4;
    pthread_mutex_unlock(&جندرا); sem_post(&بھریا);
  }
  أرجع بن_ورتیا;
}
فراغ *کھپتکار(فراغ *بن_ورتیا) {
  لكل (صحيح گنتی = 0; گنتی < 100; گنتی++) {
    sem_wait(&بھریا); pthread_mutex_lock(&جندرا);
    کل += بفر[سر]; سر = (سر + 1) % 4;
    pthread_mutex_unlock(&جندرا); sem_post(&خالی_تھاواں);
  }
  أرجع بن_ورتیا;
}
صحيح مکھ(فراغ) {
  pthread_t پہلا, دوجا;
  sem_init(&خالی_تھاواں, 0, 4); sem_init(&بھریا, 0, 0);
  pthread_create(&پہلا, عدم, پیداکار, عدم); pthread_create(&دوجا, عدم, کھپتکار, عدم);
  pthread_join(پہلا, عدم); pthread_join(دوجا, عدم);
  لکھو("%ld\n", کل);
  أرجع 0;
}
