#ضمن <stdio.h>
#ضمن <ctype.h>
/* a hand-written lexer: identifiers, numbers and operators */
صحيح اصلی(فراغ) {
  حرف منبع[] = "total = count1 + 42 * rate;";
  صحيح index = 0, نشانهها = 0;
  طالما (منبع[index]) {
    إذا (آیا_فاصله(منبع[index])) { index++; استمر; }
    صحيح شروع = index;
    إذا (آیا_حرف(منبع[index])) { طالما (آیا_حرف_یا_رقم(منبع[index])) index++; چاپ_کن("ID "); }
    وإلا إذا (آیا_رقم(منبع[index])) { طالما (آیا_رقم(منبع[index])) index++; چاپ_کن("NUM "); }
    وإلا { index++; چاپ_کن("OP "); }
    نشانهها++;
    (فراغ)شروع;
  }
  چاپ_کن("\n%d\n", نشانهها);
  أرجع 0;
}
