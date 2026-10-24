#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <pthread.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <semaphore.h>
/* concurrency: a bounded buffer of four slots between a producer and a consumer, with two semaphores and a mutex */
ਪੂਰਨ ਬਫਰ[4], ਸਿਰ = 0, ਪੂਛ = 0;
ਲੰਮਾ ਕੁੱਲ = 0;
sem_t ਖਾਲੀ_ਥਾਵਾਂ, ਭਰਿਆ;
pthread_mutex_t ਤਾਲਾ = PTHREAD_MUTEX_INITIALIZER;
ਖਾਲੀ *ਉਤਪਾਦਕ(ਖਾਲੀ *ਅਣਵਰਤਿਆ) {
  ਲਈ (ਪੂਰਨ ਮੁੱਲ_ਇਕ = 1; ਮੁੱਲ_ਇਕ <= 100; ਮੁੱਲ_ਇਕ++) {
    sem_wait(&ਖਾਲੀ_ਥਾਵਾਂ); pthread_mutex_lock(&ਤਾਲਾ);
    ਬਫਰ[ਪੂਛ] = ਮੁੱਲ_ਇਕ; ਪੂਛ = (ਪੂਛ + 1) % 4;
    pthread_mutex_unlock(&ਤਾਲਾ); sem_post(&ਭਰਿਆ);
  }
  ਵਾਪਸ ਅਣਵਰਤਿਆ;
}
ਖਾਲੀ *ਖਪਤਕਾਰ(ਖਾਲੀ *ਅਣਵਰਤਿਆ) {
  ਲਈ (ਪੂਰਨ ਗਿਣਤੀ_2 = 0; ਗਿਣਤੀ_2 < 100; ਗਿਣਤੀ_2++) {
    sem_wait(&ਭਰਿਆ); pthread_mutex_lock(&ਤਾਲਾ);
    ਕੁੱਲ += ਬਫਰ[ਸਿਰ]; ਸਿਰ = (ਸਿਰ + 1) % 4;
    pthread_mutex_unlock(&ਤਾਲਾ); sem_post(&ਖਾਲੀ_ਥਾਵਾਂ);
  }
  ਵਾਪਸ ਅਣਵਰਤਿਆ;
}
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  pthread_t ਪਹਿਲਾ, ਦੂਜਾ;
  sem_init(&ਖਾਲੀ_ਥਾਵਾਂ, 0, 4); sem_init(&ਭਰਿਆ, 0, 0);
  pthread_create(&ਪਹਿਲਾ, ਨਿਰਾ, ਉਤਪਾਦਕ, ਨਿਰਾ); pthread_create(&ਦੂਜਾ, ਨਿਰਾ, ਖਪਤਕਾਰ, ਨਿਰਾ);
  pthread_join(ਪਹਿਲਾ, ਨਿਰਾ); pthread_join(ਦੂਜਾ, ਨਿਰਾ);
  ਲਿਖੋ("%ld\n", ਕੁੱਲ);
  ਵਾਪਸ 0;
}
