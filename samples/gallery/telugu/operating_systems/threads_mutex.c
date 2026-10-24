#అన్తర్భావ <stdio.h>
#అన్తర్భావ <pthread.h>
/* threads and synchronisation: four threads add to one total, a mutex making each addition whole */
దీర్ఘ మొత్తం = 0;
pthread_mutex_t తాళం = PTHREAD_MUTEX_INITIALIZER;
శూన్య *కార్మికుడు(శూన్య *వాడని) {
  కొరకు (పూర్ణాంకం సంఖ్య = 1; సంఖ్య <= 1000; సంఖ్య++) { pthread_mutex_lock(&తాళం); మొత్తం += సంఖ్య; pthread_mutex_unlock(&తాళం); }
  తిరిగి వాడని;
}
పూర్ణాంకం ప్రధాన(శూన్య) {
  pthread_t దారాలు[4];
  కొరకు (పూర్ణాంకం index = 0; index < 4; index++) pthread_create(&దారాలు[index], ఖాళీ, కార్మికుడు, ఖాళీ);
  కొరకు (పూర్ణాంకం index = 0; index < 4; index++) pthread_join(దారాలు[index], ఖాళీ);
  రాయి("%ld\n", మొత్తం);
  తిరిగి 0;
}
