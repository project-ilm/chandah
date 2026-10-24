#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <pthread.h>
/* threads and synchronisation: four threads add to one total, a mutex making each addition whole */
ਲੰਮਾ ਕੁੱਲ = 0;
pthread_mutex_t ਤਾਲਾ = PTHREAD_MUTEX_INITIALIZER;
ਖਾਲੀ *ਕਾਮਾ(ਖਾਲੀ *ਅਣਵਰਤਿਆ) {
  ਲਈ (ਪੂਰਨ ਨੰਬਰ = 1; ਨੰਬਰ <= 1000; ਨੰਬਰ++) { pthread_mutex_lock(&ਤਾਲਾ); ਕੁੱਲ += ਨੰਬਰ; pthread_mutex_unlock(&ਤਾਲਾ); }
  ਵਾਪਸ ਅਣਵਰਤਿਆ;
}
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  pthread_t ਧਾਗੇ[4];
  ਲਈ (ਪੂਰਨ index = 0; index < 4; index++) pthread_create(&ਧਾਗੇ[index], ਨਿਰਾ, ਕਾਮਾ, ਨਿਰਾ);
  ਲਈ (ਪੂਰਨ index = 0; index < 4; index++) pthread_join(ਧਾਗੇ[index], ਨਿਰਾ);
  ਲਿਖੋ("%ld\n", ਕੁੱਲ);
  ਵਾਪਸ 0;
}
