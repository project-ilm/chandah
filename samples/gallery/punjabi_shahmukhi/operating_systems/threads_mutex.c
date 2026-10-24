#ضمن <stdio.h>
#ضمن <pthread.h>
/* threads and synchronisation: four threads add to one total, a mutex making each addition whole */
لما کل = 0;
pthread_mutex_t جندرا = PTHREAD_MUTEX_INITIALIZER;
فراغ *کامہ(فراغ *بن_ورتیا) {
  لكل (صحيح نمبر = 1; نمبر <= 1000; نمبر++) { pthread_mutex_lock(&جندرا); کل += نمبر; pthread_mutex_unlock(&جندرا); }
  أرجع بن_ورتیا;
}
صحيح مکھ(فراغ) {
  pthread_t دھاگے[4];
  لكل (صحيح index = 0; index < 4; index++) pthread_create(&دھاگے[index], عدم, کامہ, عدم);
  لكل (صحيح index = 0; index < 4; index++) pthread_join(دھاگے[index], عدم);
  لکھو("%ld\n", کل);
  أرجع 0;
}
