#ضمن <stdio.h>
/* indexing: the order of B+ tree nodes for a block size, and the levels needed for a million records */
صحيح مکيه(فراغ) {
  صحيح بلاڪ = 512, ڪنجي = 9, اشارو = 6, رڪارڊ_اشارو = 7;
  صحيح اندروني = (بلاڪ + ڪنجي) / (ڪنجي + اشارو);                  /* p pointers and p - 1 keys fit in a block */
  صحيح پن = (بلاڪ - اشارو) / (ڪنجي + رڪارڊ_اشارو);             /* keys with record pointers, and one next-leaf pointer */
  ڊگهو رڪارڊون = 1000000, پهچ = پن;
  صحيح سطحون = 1;
  طالما (پهچ < رڪارڊون) { پهچ *= اندروني; سطحون++; }
  لکو("internal %d leaf %d levels %d\n", اندروني, پن, سطحون);
  أرجع 0;
}
