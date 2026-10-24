#ضمن <stdio.h>
#ضمن <pthread.h>
#ضمن <semaphore.h>
/* concurrency: a bounded buffer of four slots between a producer and a consumer, with two semaphores and a mutex */
صحيح میانگیر[4], سر = 0, دم = 0;
دراز مجموع = 0;
sem_t خالی, پر;
pthread_mutex_t قفل = PTHREAD_MUTEX_INITIALIZER;
فراغ *تولیدکننده(فراغ *استفادهنشده) {
  لكل (صحيح مقدار = 1; مقدار <= 100; مقدار++) {
    sem_wait(&خالی); pthread_mutex_lock(&قفل);
    میانگیر[دم] = مقدار; دم = (دم + 1) % 4;
    pthread_mutex_unlock(&قفل); sem_post(&پر);
  }
  أرجع استفادهنشده;
}
فراغ *مصرفکننده(فراغ *استفادهنشده) {
  لكل (صحيح شمار = 0; شمار < 100; شمار++) {
    sem_wait(&پر); pthread_mutex_lock(&قفل);
    مجموع += میانگیر[سر]; سر = (سر + 1) % 4;
    pthread_mutex_unlock(&قفل); sem_post(&خالی);
  }
  أرجع استفادهنشده;
}
صحيح اصلی(فراغ) {
  pthread_t اولی, دومی;
  sem_init(&خالی, 0, 4); sem_init(&پر, 0, 0);
  pthread_create(&اولی, عدم, تولیدکننده, عدم); pthread_create(&دومی, عدم, مصرفکننده, عدم);
  pthread_join(اولی, عدم); pthread_join(دومی, عدم);
  چاپ_کن("%ld\n", مجموع);
  أرجع 0;
}
