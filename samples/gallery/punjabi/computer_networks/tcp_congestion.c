#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
/* TCP congestion control: slow start, congestion avoidance, and a timeout at round 8 */
ਪੂਰਨ ਮੁੱਖ(ਖਾਲੀ) {
  ਪੂਰਨ ਖਿੜਕੀ = 1, ਹੱਦ = 16;
  ਲਈ (ਪੂਰਨ round = 1; round <= 12; round++) {
    ਲਿਖੋ("%d ", ਖਿੜਕੀ);
    ਜੇ (round == 8) { ਹੱਦ = ਖਿੜਕੀ / 2; ਖਿੜਕੀ = 1; }
    ਨਹੀਂਤਾਂ ਜੇ (ਖਿੜਕੀ < ਹੱਦ) ਖਿੜਕੀ *= 2;
    ਨਹੀਂਤਾਂ ਖਿੜਕੀ += 1;
  }
  ਲਿਖੋ("\n");
  ਵਾਪਸ 0;
}
