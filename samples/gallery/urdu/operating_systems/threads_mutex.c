#شامل <stdio.h>
#شامل <pthread.h>
/* threads and synchronisation: four threads add to one total, a mutex making each addition whole */
طویل کل = 0;
pthread_mutex_t تالا = PTHREAD_MUTEX_INITIALIZER;
خالی *کارکن(خالی *غیر_مستعمل) {
  برائے (صحیح نمبر = 1; نمبر <= 1000; نمبر++) { pthread_mutex_lock(&تالا); کل += نمبر; pthread_mutex_unlock(&تالا); }
  واپس غیر_مستعمل;
}
صحیح مین(خالی) {
  pthread_t دھاگے[4];
  برائے (صحیح index = 0; index < 4; index++) pthread_create(&دھاگے[index], تہی, کارکن, تہی);
  برائے (صحیح index = 0; index < 4; index++) pthread_join(دھاگے[index], تہی);
  لکھو("%ld\n", کل);
  واپس 0;
}
