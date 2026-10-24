#ضمن <stdio.h>
/* memory management: translate virtual addresses with a page table, page size 1024 */
صحيح مکھ(فراغ) {
  صحيح جدول[8] = {5, 2, -1, 7, 1, -1, 3, 0}, پتے[] = {100, 2048, 3100, 7000, 5000};
  لكل (صحيح index = 0; index < 5; index++) {
    صحيح ورقہ = پتے[index] / 1024, وتھ = پتے[index] % 1024;
    إذا (جدول[ورقہ] < 0) لکھو("fault ");
    وإلا لکھو("%d ", جدول[ورقہ] * 1024 + وتھ);
  }
  لکھو("\n");
  أرجع 0;
}
