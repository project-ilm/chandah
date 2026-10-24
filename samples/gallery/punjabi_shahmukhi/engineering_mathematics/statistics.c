#ضمن <stdio.h>
#ضمن <math.h>
/* probability and statistics: mean, median, mode and standard deviation of sorted values */
صحيح مکھ(فراغ) {
  صحيح مل[] = {2, 3, 3, 5, 7, 8, 8, 8, 9}, گنتی = 9, منوال = مل[0], بہترین = 0;
  مزدوج کل = 0, پھیلاؤ = 0;
  لكل (صحيح index = 0; index < گنتی; index++) کل += مل[index];
  مزدوج اوسط = کل / گنتی;
  لكل (صحيح index = 0; index < گنتی; index++) پھیلاؤ += (مل[index] - اوسط) * (مل[index] - اوسط);
  لكل (صحيح index = 0, لگاتار = 1; index < گنتی; index++, لگاتار = (index < گنتی && مل[index] == مل[index - 1]) ? لگاتار + 1 : 1)
    إذا (لگاتار > بہترین) { بہترین = لگاتار; منوال = مل[index]; }
  لکھو("mean %.2f median %d mode %d deviation %.2f\n", اوسط, مل[گنتی / 2], منوال, جذر(پھیلاؤ / گنتی));
  أرجع 0;
}
