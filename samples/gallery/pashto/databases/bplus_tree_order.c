#ضمن <stdio.h>
/* indexing: the order of B+ tree nodes for a block size, and the levels needed for a million records */
صحيح اصلي(فراغ) {
  صحيح بلاک = 512, کیلي = 9, اشاره_ګر = 6, ریکارډ_اشاره_ګر = 7;
  صحيح دننی = (بلاک + کیلي) / (کیلي + اشاره_ګر);                  /* p pointers and p - 1 keys fit in a block */
  صحيح ونې_پاڼه = (بلاک - اشاره_ګر) / (کیلي + ریکارډ_اشاره_ګر);             /* keys with record pointers, and one next-leaf pointer */
  اوږد ریکارډونه = 1000000, رسېدنه = ونې_پاڼه;
  صحيح پوړونه = 1;
  طالما (رسېدنه < ریکارډونه) { رسېدنه *= دننی; پوړونه++; }
  چاپ_کړه("internal %d leaf %d levels %d\n", دننی, ونې_پاڼه, پوړونه);
  أرجع 0;
}
