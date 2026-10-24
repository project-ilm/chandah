#अन्तर्भाव <stdio.h>
/* switching performance: transmission and propagation delay, and stop-and-wait link utilisation */
पूर्णाङ्क मुख्यम्(शून्य) {
  द्विगुण आकारः = 1000 * 8, दरः = 1e6, अन्तरम् = 2e6, जवः = 2e8;   /* bits, bits per second, metres, metres per second */
  द्विगुण सम्प्रेषणम् = आकारः / दरः, सञ्चरणम् = अन्तरम् / जवः;
  प्रारूप_लिख("%.1f ms %.1f ms %.2f\n", सम्प्रेषणम् * 1000, सञ्चरणम् * 1000, सम्प्रेषणम् / (सम्प्रेषणम् + 2 * सञ्चरणम्));
  प्रत्यागम 0;
}
