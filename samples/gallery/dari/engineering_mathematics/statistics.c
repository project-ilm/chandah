#ضمن <stdio.h>
#ضمن <math.h>
/* probability and statistics: mean, median, mode and standard deviation of sorted values */
صحيح اصلی(فراغ) {
  صحيح مقادیر[] = {2, 3, 3, 5, 7, 8, 8, 8, 9}, شمار = 9, نما = مقادیر[0], بهترین = 0;
  مزدوج مجموع = 0, پراکندگی = 0;
  لكل (صحيح index = 0; index < شمار; index++) مجموع += مقادیر[index];
  مزدوج میانگین = مجموع / شمار;
  لكل (صحيح index = 0; index < شمار; index++) پراکندگی += (مقادیر[index] - میانگین) * (مقادیر[index] - میانگین);
  لكل (صحيح index = 0, پیاپی = 1; index < شمار; index++, پیاپی = (index < شمار && مقادیر[index] == مقادیر[index - 1]) ? پیاپی + 1 : 1)
    إذا (پیاپی > بهترین) { بهترین = پیاپی; نما = مقادیر[index]; }
  چاپ_کن("mean %.2f median %d mode %d deviation %.2f\n", میانگین, مقادیر[شمار / 2], نما, جذر(پراکندگی / شمار));
  أرجع 0;
}
