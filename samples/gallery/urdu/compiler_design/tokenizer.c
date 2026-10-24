#شامل <stdio.h>
#شامل <ctype.h>
/* a hand-written lexer: identifiers, numbers and operators */
صحیح مین(خالی) {
  حرف ماخذ[] = "total = count1 + 42 * rate;";
  صحیح index = 0, علامات = 0;
  جب (ماخذ[index]) {
    اگر (خلا_ہے(ماخذ[index])) { index++; جاری; }
    صحیح آغاز = index;
    اگر (حرف_ہے(ماخذ[index])) { جب (حرف_یا_ہندسہ(ماخذ[index])) index++; لکھو("ID "); }
    ورنہ اگر (ہندسہ_ہے(ماخذ[index])) { جب (ہندسہ_ہے(ماخذ[index])) index++; لکھو("NUM "); }
    ورنہ { index++; لکھو("OP "); }
    علامات++;
    (خالی)آغاز;
  }
  لکھو("\n%d\n", علامات);
  واپس 0;
}
