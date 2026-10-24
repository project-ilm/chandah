#ضمن <stdio.h>
/* memory management: translate virtual addresses with a page table, page size 1024 */
صحيح مکيه(فراغ) {
  صحيح جدول[8] = {5, 2, -1, 7, 1, -1, 3, 0}, پتا[] = {100, 2048, 3100, 7000, 5000};
  لكل (صحيح index = 0; index < 5; index++) {
    صحيح صفحو = پتا[index] / 1024, وٿي = پتا[index] % 1024;
    إذا (جدول[صفحو] < 0) لکو("fault ");
    وإلا لکو("%d ", جدول[صفحو] * 1024 + وٿي);
  }
  لکو("\n");
  أرجع 0;
}
