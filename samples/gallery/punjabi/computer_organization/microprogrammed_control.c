#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* control unit design: a microprogrammed sequencer; each microinstruction names its control signals and the next one */
ਅਚਲ ਅੱਖਰ *ਸੰਕੇਤ_2[] = {"PC->MAR", "MEM->MDR PC+1", "MDR->IR", "dispatch", "IR->MAR", "MEM->MDR", "MDR+ACC->ACC", "MDR->ACC"};
ਪੂਰਨ ਅਗਲਾ[] = {1, 2, 3, -1, 5, 6, 0, 0};
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਪੂਰਨ ਸ਼ੁਰੂ[2] = {4, 4}, ਅੰਤ[2] = {6, 7};   /* ADD and LOAD share the operand fetch, then differ */
  ਲਈ (ਪੂਰਨ ਕਿਸਮ = 0; ਕਿਸਮ < 2; ਕਿਸਮ++) {
    ਪੂਰਨ ਪਤਾ = 0;
    ਜਦੋਂ (ਪਤਾ != -1) {
      ਲਿਖੋ("%s; ", ਸੰਕੇਤ_2[ਪਤਾ]);
      ਪਤਾ = ਅਗਲਾ[ਪਤਾ];
    }
    ਲਈ (ਪਤਾ = ਸ਼ੁਰੂ[ਕਿਸਮ]; ਪਤਾ != 6; ਪਤਾ = ਅਗਲਾ[ਪਤਾ]) ਲਿਖੋ("%s; ", ਸੰਕੇਤ_2[ਪਤਾ]);
    ਲਿਖੋ("%s\n", ਸੰਕੇਤ_2[ਅੰਤ[ਕਿਸਮ]]);
  }
  ਵਾਪਸ 0;
}
