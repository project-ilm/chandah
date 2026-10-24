#అన్తర్భావ <stdio.h>
/* indexing: the order of B+ tree nodes for a block size, and the levels needed for a million records */
పూర్ణాంకం ప్రధాన(శూన్య) {
  పూర్ణాంకం ఖండం = 512, కీలకం = 9, సూచిక = 6, రికార్డు_సూచిక = 7;
  పూర్ణాంకం అంతర్గత = (ఖండం + కీలకం) / (కీలకం + సూచిక);                  /* p pointers and p - 1 keys fit in a block */
  పూర్ణాంకం ఆకు = (ఖండం - సూచిక) / (కీలకం + రికార్డు_సూచిక);             /* keys with record pointers, and one next-leaf pointer */
  దీర్ఘ రికార్డులు = 1000000, వ్యాప్తి = ఆకు;
  పూర్ణాంకం స్థాయిలు = 1;
  అయితే (వ్యాప్తి < రికార్డులు) { వ్యాప్తి *= అంతర్గత; స్థాయిలు++; }
  రాయి("internal %d leaf %d levels %d\n", అంతర్గత, ఆకు, స్థాయిలు);
  తిరిగి 0;
}
