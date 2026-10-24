#ضمن <stdio.h>
#ضمن <pthread.h>
#ضمن <semaphore.h>
/* concurrency: a bounded buffer of four slots between a producer and a consumer, with two semaphores and a mutex */
صحيح بفر[4], سر = 0, پڇ = 0;
ڊگهو ڪل = 0;
sem_t خالي_جايون, ڀريل;
pthread_mutex_t تالو = PTHREAD_MUTEX_INITIALIZER;
فراغ *پيداوار_ڪندڙ(فراغ *اڻ_استعمال_ٿيل) {
  لكل (صحيح قدر = 1; قدر <= 100; قدر++) {
    sem_wait(&خالي_جايون); pthread_mutex_lock(&تالو);
    بفر[پڇ] = قدر; پڇ = (پڇ + 1) % 4;
    pthread_mutex_unlock(&تالو); sem_post(&ڀريل);
  }
  أرجع اڻ_استعمال_ٿيل;
}
فراغ *استعمال_ڪندڙ(فراغ *اڻ_استعمال_ٿيل) {
  لكل (صحيح ڳڻپ = 0; ڳڻپ < 100; ڳڻپ++) {
    sem_wait(&ڀريل); pthread_mutex_lock(&تالو);
    ڪل += بفر[سر]; سر = (سر + 1) % 4;
    pthread_mutex_unlock(&تالو); sem_post(&خالي_جايون);
  }
  أرجع اڻ_استعمال_ٿيل;
}
صحيح مکيه(فراغ) {
  pthread_t پهريون, ٻيو;
  sem_init(&خالي_جايون, 0, 4); sem_init(&ڀريل, 0, 0);
  pthread_create(&پهريون, عدم, پيداوار_ڪندڙ, عدم); pthread_create(&ٻيو, عدم, استعمال_ڪندڙ, عدم);
  pthread_join(پهريون, عدم); pthread_join(ٻيو, عدم);
  لکو("%ld\n", ڪل);
  أرجع 0;
}
