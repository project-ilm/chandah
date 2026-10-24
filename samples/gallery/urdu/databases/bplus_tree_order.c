#شامل <stdio.h>
/* indexing: the order of B+ tree nodes for a block size, and the levels needed for a million records */
صحیح مین(خالی) {
  صحیح بلاک = 512, کلید = 9, اشارہ_گر = 6, ریکارڈ_اشارہ_گر = 7;
  صحیح اندرونی_2 = (بلاک + کلید) / (کلید + اشارہ_گر);                  /* p pointers and p - 1 keys fit in a block */
  صحیح برگ = (بلاک - اشارہ_گر) / (کلید + ریکارڈ_اشارہ_گر);             /* keys with record pointers, and one next-leaf pointer */
  طویل اندراجات = 1000000, رسائی = برگ;
  صحیح سطحیں = 1;
  جب (رسائی < اندراجات) { رسائی *= اندرونی_2; سطحیں++; }
  لکھو("internal %d leaf %d levels %d\n", اندرونی_2, برگ, سطحیں);
  واپس 0;
}
