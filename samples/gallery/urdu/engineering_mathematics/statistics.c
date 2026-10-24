#شامل <stdio.h>
#شامل <math.h>
/* probability and statistics: mean, median, mode and standard deviation of sorted values */
صحیح مین(خالی) {
  صحیح اقدار[] = {2, 3, 3, 5, 7, 8, 8, 8, 9}, گنتی = 9, منوال = اقدار[0], بہترین = 0;
  دوہرا کل = 0, پھیلاؤ = 0;
  برائے (صحیح index = 0; index < گنتی; index++) کل += اقدار[index];
  دوہرا اوسط = کل / گنتی;
  برائے (صحیح index = 0; index < گنتی; index++) پھیلاؤ += (اقدار[index] - اوسط) * (اقدار[index] - اوسط);
  برائے (صحیح index = 0, تسلسل = 1; index < گنتی; index++, تسلسل = (index < گنتی && اقدار[index] == اقدار[index - 1]) ? تسلسل + 1 : 1)
    اگر (تسلسل > بہترین) { بہترین = تسلسل; منوال = اقدار[index]; }
  لکھو("mean %.2f median %d mode %d deviation %.2f\n", اوسط, اقدار[گنتی / 2], منوال, جذر(پھیلاؤ / گنتی));
  واپس 0;
}
