#ضمن <stdio.h>
/* indexing: the order of B+ tree nodes for a block size, and the levels needed for a million records */
صحيح مکھ(فراغ) {
  صحيح بلاک = 512, کنجی = 9, اشارہ_گر = 6, ریکارڈ_اشارہ_گر = 7;
  صحيح اندرونی = (بلاک + کنجی) / (کنجی + اشارہ_گر);                  /* p pointers and p - 1 keys fit in a block */
  صحيح پتی = (بلاک - اشارہ_گر) / (کنجی + ریکارڈ_اشارہ_گر);             /* keys with record pointers, and one next-leaf pointer */
  لما ریکارڈاں = 1000000, اپڑ = پتی;
  صحيح پدھراں = 1;
  طالما (اپڑ < ریکارڈاں) { اپڑ *= اندرونی; پدھراں++; }
  لکھو("internal %d leaf %d levels %d\n", اندرونی, پتی, پدھراں);
  أرجع 0;
}
