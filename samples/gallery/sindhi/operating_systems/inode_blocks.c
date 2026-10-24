#ضمن <stdio.h>
/* file systems: the largest file an inode with 12 direct, one single, one double and one triple indirect pointer can map */
صحيح مکيه(فراغ) {
  ڊگهو ڊگهو بلاڪ = 1024, اشارا = بلاڪ / 4;
  ڊگهو ڊگهو بلاڪون = 12 + اشارا + اشارا * اشارا + اشارا * اشارا * اشارا;
  لکو("%lld blocks, %lld bytes\n", بلاڪون, بلاڪون * بلاڪ);
  أرجع 0;
}
