#ضمن <stdio.h>
#ضمن <pthread.h>
/* threads and synchronisation: four threads add to one total, a mutex making each addition whole */
اوږد ټول = 0;
pthread_mutex_t قلف = PTHREAD_MUTEX_INITIALIZER;
فراغ *کارګر(فراغ *ناکارول_شوی) {
  لكل (صحيح شمېره = 1; شمېره <= 1000; شمېره++) { pthread_mutex_lock(&قلف); ټول += شمېره; pthread_mutex_unlock(&قلف); }
  أرجع ناکارول_شوی;
}
صحيح اصلي(فراغ) {
  pthread_t تارونه[4];
  لكل (صحيح index = 0; index < 4; index++) pthread_create(&تارونه[index], عدم, کارګر, عدم);
  لكل (صحيح index = 0; index < 4; index++) pthread_join(تارونه[index], عدم);
  چاپ_کړه("%ld\n", ټول);
  أرجع 0;
}
