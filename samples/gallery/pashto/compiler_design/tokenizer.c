#ضمن <stdio.h>
#ضمن <ctype.h>
/* a hand-written lexer: identifiers, numbers and operators */
صحيح اصلي(فراغ) {
  حرف سرچینه[] = "total = count1 + 42 * rate;";
  صحيح index = 0, نښې = 0;
  طالما (سرچینه[index]) {
    إذا (که_تشه(سرچینه[index])) { index++; استمر; }
    صحيح پیل = index;
    إذا (که_توری(سرچینه[index])) { طالما (که_توری_یا_عدد(سرچینه[index])) index++; چاپ_کړه("ID "); }
    وإلا إذا (که_عدد(سرچینه[index])) { طالما (که_عدد(سرچینه[index])) index++; چاپ_کړه("NUM "); }
    وإلا { index++; چاپ_کړه("OP "); }
    نښې++;
    (فراغ)پیل;
  }
  چاپ_کړه("\n%d\n", نښې);
  أرجع 0;
}
