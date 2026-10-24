#ضمن <stdio.h>
#ضمن <pthread.h>
/* threads and synchronisation: four threads add to one total, a mutex making each addition whole */
ڊگهو ڪل = 0;
pthread_mutex_t تالو = PTHREAD_MUTEX_INITIALIZER;
فراغ *ڪم_ڪندڙ(فراغ *اڻ_استعمال_ٿيل) {
  لكل (صحيح نمبر = 1; نمبر <= 1000; نمبر++) { pthread_mutex_lock(&تالو); ڪل += نمبر; pthread_mutex_unlock(&تالو); }
  أرجع اڻ_استعمال_ٿيل;
}
صحيح مکيه(فراغ) {
  pthread_t ڌاڳا[4];
  لكل (صحيح index = 0; index < 4; index++) pthread_create(&ڌاڳا[index], عدم, ڪم_ڪندڙ, عدم);
  لكل (صحيح index = 0; index < 4; index++) pthread_join(ڌاڳا[index], عدم);
  لکو("%ld\n", ڪل);
  أرجع 0;
}
