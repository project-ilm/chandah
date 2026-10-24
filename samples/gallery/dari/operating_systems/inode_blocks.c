#ضمن <stdio.h>
/* file systems: the largest file an inode with 12 direct, one single, one double and one triple indirect pointer can map */
صحيح اصلی(فراغ) {
  دراز دراز بلوک = 1024, اشارهگرها = بلوک / 4;
  دراز دراز بلوکها = 12 + اشارهگرها + اشارهگرها * اشارهگرها + اشارهگرها * اشارهگرها * اشارهگرها;
  چاپ_کن("%lld blocks, %lld bytes\n", بلوکها, بلوکها * بلوک);
  أرجع 0;
}
