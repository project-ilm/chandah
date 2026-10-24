#ضمن <stdio.h>
/* file systems: the largest file an inode with 12 direct, one single, one double and one triple indirect pointer can map */
صحيح مکھ(فراغ) {
  لما لما بلاک = 1024, سوچکاں = بلاک / 4;
  لما لما بلاکاں = 12 + سوچکاں + سوچکاں * سوچکاں + سوچکاں * سوچکاں * سوچکاں;
  لکھو("%lld blocks, %lld bytes\n", بلاکاں, بلاکاں * بلاک);
  أرجع 0;
}
