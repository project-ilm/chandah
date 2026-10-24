#شامل <stdio.h>
/* file systems: the largest file an inode with 12 direct, one single, one double and one triple indirect pointer can map */
صحیح مین(خالی) {
  طویل طویل بلاک = 1024, اشارے = بلاک / 4;
  طویل طویل بلاکیں = 12 + اشارے + اشارے * اشارے + اشارے * اشارے * اشارے;
  لکھو("%lld blocks, %lld bytes\n", بلاکیں, بلاکیں * بلاک);
  واپس 0;
}
