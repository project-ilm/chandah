#అన్తర్భావ <stdio.h>
/* file systems: the largest file an inode with 12 direct, one single, one double and one triple indirect pointer can map */
పూర్ణాంకం ప్రధాన(శూన్య) {
  దీర్ఘ దీర్ఘ ఖండం = 1024, సూచికలు = ఖండం / 4;
  దీర్ఘ దీర్ఘ ఖండాలు = 12 + సూచికలు + సూచికలు * సూచికలు + సూచికలు * సూచికలు * సూచికలు;
  రాయి("%lld blocks, %lld bytes\n", ఖండాలు, ఖండాలు * ఖండం);
  తిరిగి 0;
}
