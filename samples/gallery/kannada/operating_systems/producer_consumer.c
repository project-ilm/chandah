#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <pthread.h>
#ಅನ್ತರ್ಭಾವ <semaphore.h>
/* concurrency: a bounded buffer of four slots between a producer and a consumer, with two semaphores and a mutex */
ಪೂರ್ಣಾಂಕ ಬಫರ್[4], ತಲೆ = 0, ಬಾಲ = 0;
ದೀರ್ಘ ಒಟ್ಟು = 0;
sem_t ಖಾಲಿಗಳು, ತುಂಬಿದ;
pthread_mutex_t ಬೀಗ = PTHREAD_MUTEX_INITIALIZER;
ಶೂನ್ಯ *ಉತ್ಪಾದಕ(ಶೂನ್ಯ *ಬಳಸದ) {
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ = 1; ಮೌಲ್ಯ <= 100; ಮೌಲ್ಯ++) {
    sem_wait(&ಖಾಲಿಗಳು); pthread_mutex_lock(&ಬೀಗ);
    ಬಫರ್[ಬಾಲ] = ಮೌಲ್ಯ; ಬಾಲ = (ಬಾಲ + 1) % 4;
    pthread_mutex_unlock(&ಬೀಗ); sem_post(&ತುಂಬಿದ);
  }
  ಹಿಂತಿರುಗಿ ಬಳಸದ;
}
ಶೂನ್ಯ *ಗ್ರಾಹಕ(ಶೂನ್ಯ *ಬಳಸದ) {
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ ಎಣಿಕೆ_2 = 0; ಎಣಿಕೆ_2 < 100; ಎಣಿಕೆ_2++) {
    sem_wait(&ತುಂಬಿದ); pthread_mutex_lock(&ಬೀಗ);
    ಒಟ್ಟು += ಬಫರ್[ತಲೆ]; ತಲೆ = (ತಲೆ + 1) % 4;
    pthread_mutex_unlock(&ಬೀಗ); sem_post(&ಖಾಲಿಗಳು);
  }
  ಹಿಂತಿರುಗಿ ಬಳಸದ;
}
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  pthread_t ಮೊದಲ, ಎರಡನೇ;
  sem_init(&ಖಾಲಿಗಳು, 0, 4); sem_init(&ತುಂಬಿದ, 0, 0);
  pthread_create(&ಮೊದಲ, ಖಾಲಿ, ಉತ್ಪಾದಕ, ಖಾಲಿ); pthread_create(&ಎರಡನೇ, ಖಾಲಿ, ಗ್ರಾಹಕ, ಖಾಲಿ);
  pthread_join(ಮೊದಲ, ಖಾಲಿ); pthread_join(ಎರಡನೇ, ಖಾಲಿ);
  ಬರೆ("%ld\n", ಒಟ್ಟು);
  ಹಿಂತಿರುಗಿ 0;
}
