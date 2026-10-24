#అన్తర్భావ <stdio.h>
#అన్తర్భావ <string.h>
/* number representation: the sign, exponent and fraction of an IEEE 754 single-precision number */
పూర్ణాంకం ప్రధాన(శూన్య) {
  దశాంశం సంఖ్య = -6.25f;
  గుర్తులేని బిట్లు;
  జ్ఞాపకం_నకలు(&బిట్లు, &సంఖ్య, పరిమాణం బిట్లు);
  రాయి("sign %u exponent %u fraction %06X\n", బిట్లు >> 31, ((బిట్లు >> 23) & 0xFF) - 127, బిట్లు & 0x7FFFFF);
  తిరిగి 0;
}
