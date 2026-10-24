#ضمن <stdio.h>
#ضمن <math.h>
/* probability and statistics: mean, median, mode and standard deviation of sorted values */
صحيح مکيه(فراغ) {
  صحيح قدرون[] = {2, 3, 3, 5, 7, 8, 8, 8, 9}, ڳڻپ = 9, گهڻائي = قدرون[0], بهترين = 0;
  مزدوج ڪل = 0, پکيڙ = 0;
  لكل (صحيح index = 0; index < ڳڻپ; index++) ڪل += قدرون[index];
  مزدوج سراسري = ڪل / ڳڻپ;
  لكل (صحيح index = 0; index < ڳڻپ; index++) پکيڙ += (قدرون[index] - سراسري) * (قدرون[index] - سراسري);
  لكل (صحيح index = 0, لاڳيتو = 1; index < ڳڻپ; index++, لاڳيتو = (index < ڳڻپ && قدرون[index] == قدرون[index - 1]) ? لاڳيتو + 1 : 1)
    إذا (لاڳيتو > بهترين) { بهترين = لاڳيتو; گهڻائي = قدرون[index]; }
  لکو("mean %.2f median %d mode %d deviation %.2f\n", سراسري, قدرون[ڳڻپ / 2], گهڻائي, جذر(پکيڙ / ڳڻپ));
  أرجع 0;
}
