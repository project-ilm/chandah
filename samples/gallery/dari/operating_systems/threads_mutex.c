#ضمن <stdio.h>
#ضمن <pthread.h>
/* threads and synchronisation: four threads add to one total, a mutex making each addition whole */
دراز مجموع = 0;
pthread_mutex_t قفل = PTHREAD_MUTEX_INITIALIZER;
فراغ *کارگر(فراغ *استفادهنشده) {
  لكل (صحيح شماره = 1; شماره <= 1000; شماره++) { pthread_mutex_lock(&قفل); مجموع += شماره; pthread_mutex_unlock(&قفل); }
  أرجع استفادهنشده;
}
صحيح اصلی(فراغ) {
  pthread_t نخها[4];
  لكل (صحيح index = 0; index < 4; index++) pthread_create(&نخها[index], عدم, کارگر, عدم);
  لكل (صحيح index = 0; index < 4; index++) pthread_join(نخها[index], عدم);
  چاپ_کن("%ld\n", مجموع);
  أرجع 0;
}
