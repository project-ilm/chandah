#ضمن <stdio.h>
/* file systems: the largest file an inode with 12 direct, one single, one double and one triple indirect pointer can map */
صحيح اصلي(فراغ) {
  اوږد اوږد بلاک = 1024, اشارې = بلاک / 4;
  اوږد اوږد بلاکونه = 12 + اشارې + اشارې * اشارې + اشارې * اشارې * اشارې;
  چاپ_کړه("%lld blocks, %lld bytes\n", بلاکونه, بلاکونه * بلاک);
  أرجع 0;
}
