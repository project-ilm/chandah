#ضمن <stdio.h>
/* indexing: the order of B+ tree nodes for a block size, and the levels needed for a million records */
صحيح اصلی(فراغ) {
  صحيح بلوک = 512, کلید = 9, اشاره_گر = 6, رکورد_اشاره_گر = 7;
  صحيح داخلی = (بلوک + کلید) / (کلید + اشاره_گر);                  /* p pointers and p - 1 keys fit in a block */
  صحيح برگ = (بلوک - اشاره_گر) / (کلید + رکورد_اشاره_گر);             /* keys with record pointers, and one next-leaf pointer */
  دراز رکوردها = 1000000, دسترسی = برگ;
  صحيح سطوح = 1;
  طالما (دسترسی < رکوردها) { دسترسی *= داخلی; سطوح++; }
  چاپ_کن("internal %d leaf %d levels %d\n", داخلی, برگ, سطوح);
  أرجع 0;
}
