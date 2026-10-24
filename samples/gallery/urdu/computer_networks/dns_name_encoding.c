#شامل <stdio.h>
#شامل <string.h>
/* DNS: a domain name in the wire format of a query, each label preceded by its length, ending with zero */
صحیح مین(خالی) {
  ثابت حرف *متن = "www.example.com";
  غیرعلامتی حرف برآمد[64]; صحیح سائز = 0, آغاز = 0;
  برائے (صحیح index = 0; ; index++)
    اگر (متن[index] == '.' || متن[index] == '\0') {
      برآمد[سائز++] = index - آغاز;
      حافظہ_نقل(برآمد + سائز, متن + آغاز, index - آغاز); سائز += index - آغاز;
      آغاز = index + 1;
      اگر (متن[index] == '\0') توڑو;
    }
  برآمد[سائز++] = 0;
  برائے (صحیح index = 0; index < سائز; index++) لکھو(برآمد[index] < 32 ? "[%d]" : "%c", برآمد[index]);
  لکھو(" (%d bytes)\n", سائز);
  واپس 0;
}
