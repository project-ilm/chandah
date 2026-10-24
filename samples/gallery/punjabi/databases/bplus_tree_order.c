#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* indexing: the order of B+ tree nodes for a block size, and the levels needed for a million records */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਪੂਰਨ ਖੰਡ = 512, ਕੁੰਜੀ = 9, ਸੂਚਕ = 6, ਰਿਕਾਰਡ_ਸੂਚਕ = 7;
  ਪੂਰਨ ਅੰਦਰੂਨੀ = (ਖੰਡ + ਕੁੰਜੀ) / (ਕੁੰਜੀ + ਸੂਚਕ);                  /* p pointers and p - 1 keys fit in a block */
  ਪੂਰਨ ਪੱਤੀ = (ਖੰਡ - ਸੂਚਕ) / (ਕੁੰਜੀ + ਰਿਕਾਰਡ_ਸੂਚਕ);             /* keys with record pointers, and one next-leaf pointer */
  ਲੰਮਾ ਰਿਕਾਰਡਾਂ = 1000000, ਪਹੁੰਚ = ਪੱਤੀ;
  ਪੂਰਨ ਪੱਧਰ = 1;
  ਜਦੋਂ (ਪਹੁੰਚ < ਰਿਕਾਰਡਾਂ) { ਪਹੁੰਚ *= ਅੰਦਰੂਨੀ; ਪੱਧਰ++; }
  ਲਿਖੋ("internal %d leaf %d levels %d\n", ਅੰਦਰੂਨੀ, ਪੱਤੀ, ਪੱਧਰ);
  ਵਾਪਸ 0;
}
