#ضمن <stdio.h>
#ضمن <pthread.h>
#ضمن <semaphore.h>
/* concurrency: a bounded buffer of four slots between a producer and a consumer, with two semaphores and a mutex */
صحيح بفر[4], سر = 0, لکۍ = 0;
اوږد ټول = 0;
sem_t تشه, ډک;
pthread_mutex_t قلف = PTHREAD_MUTEX_INITIALIZER;
فراغ *تولیدوونکی(فراغ *ناکارول_شوی) {
  لكل (صحيح ارزښت = 1; ارزښت <= 100; ارزښت++) {
    sem_wait(&تشه); pthread_mutex_lock(&قلف);
    بفر[لکۍ] = ارزښت; لکۍ = (لکۍ + 1) % 4;
    pthread_mutex_unlock(&قلف); sem_post(&ډک);
  }
  أرجع ناکارول_شوی;
}
فراغ *مصرفوونکی(فراغ *ناکارول_شوی) {
  لكل (صحيح شمېر = 0; شمېر < 100; شمېر++) {
    sem_wait(&ډک); pthread_mutex_lock(&قلف);
    ټول += بفر[سر]; سر = (سر + 1) % 4;
    pthread_mutex_unlock(&قلف); sem_post(&تشه);
  }
  أرجع ناکارول_شوی;
}
صحيح اصلي(فراغ) {
  pthread_t لومړی, دوهم;
  sem_init(&تشه, 0, 4); sem_init(&ډک, 0, 0);
  pthread_create(&لومړی, عدم, تولیدوونکی, عدم); pthread_create(&دوهم, عدم, مصرفوونکی, عدم);
  pthread_join(لومړی, عدم); pthread_join(دوهم, عدم);
  چاپ_کړه("%ld\n", ټول);
  أرجع 0;
}
