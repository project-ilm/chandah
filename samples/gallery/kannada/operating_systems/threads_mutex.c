#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <pthread.h>
/* threads and synchronisation: four threads add to one total, a mutex making each addition whole */
ದೀರ್ಘ ಒಟ್ಟು = 0;
pthread_mutex_t ಬೀಗ = PTHREAD_MUTEX_INITIALIZER;
ಶೂನ್ಯ *ಕೆಲಸಗಾರ(ಶೂನ್ಯ *ಬಳಸದ) {
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ ಸಂಖ್ಯೆ = 1; ಸಂಖ್ಯೆ <= 1000; ಸಂಖ್ಯೆ++) { pthread_mutex_lock(&ಬೀಗ); ಒಟ್ಟು += ಸಂಖ್ಯೆ; pthread_mutex_unlock(&ಬೀಗ); }
  ಹಿಂತಿರುಗಿ ಬಳಸದ;
}
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಶೂನ್ಯ) {
  pthread_t ಎಳೆಗಳು[4];
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ index = 0; index < 4; index++) pthread_create(&ಎಳೆಗಳು[index], ಖಾಲಿ, ಕೆಲಸಗಾರ, ಖಾಲಿ);
  ಗಾಗಿ (ಪೂರ್ಣಾಂಕ index = 0; index < 4; index++) pthread_join(ಎಳೆಗಳು[index], ಖಾಲಿ);
  ಬರೆ("%ld\n", ಒಟ್ಟು);
  ಹಿಂತಿರುಗಿ 0;
}
