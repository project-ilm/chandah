#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <math.h>
/* probability and statistics: mean, median, mode and standard deviation of sorted values */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਪੂਰਨ ਮੁੱਲ[] = {2, 3, 3, 5, 7, 8, 8, 8, 9}, ਗਿਣਤੀ_2 = 9, ਬਹੁਲਕ = ਮੁੱਲ[0], ਉੱਤਮ = 0;
  ਦੁੱਗਣਾ ਕੁੱਲ = 0, ਫੈਲਾਅ = 0;
  ਲਈ (ਪੂਰਨ index = 0; index < ਗਿਣਤੀ_2; index++) ਕੁੱਲ += ਮੁੱਲ[index];
  ਦੁੱਗਣਾ ਔਸਤ = ਕੁੱਲ / ਗਿਣਤੀ_2;
  ਲਈ (ਪੂਰਨ index = 0; index < ਗਿਣਤੀ_2; index++) ਫੈਲਾਅ += (ਮੁੱਲ[index] - ਔਸਤ) * (ਮੁੱਲ[index] - ਔਸਤ);
  ਲਈ (ਪੂਰਨ index = 0, ਲੜੀਵਾਰ = 1; index < ਗਿਣਤੀ_2; index++, ਲੜੀਵਾਰ = (index < ਗਿਣਤੀ_2 && ਮੁੱਲ[index] == ਮੁੱਲ[index - 1]) ? ਲੜੀਵਾਰ + 1 : 1)
    ਜੇ (ਲੜੀਵਾਰ > ਉੱਤਮ) { ਉੱਤਮ = ਲੜੀਵਾਰ; ਬਹੁਲਕ = ਮੁੱਲ[index]; }
  ਲਿਖੋ("mean %.2f median %d mode %d deviation %.2f\n", ਔਸਤ, ਮੁੱਲ[ਗਿਣਤੀ_2 / 2], ਬਹੁਲਕ, ਵਰਗਮੂਲ(ਫੈਲਾਅ / ਗਿਣਤੀ_2));
  ਵਾਪਸ 0;
}
