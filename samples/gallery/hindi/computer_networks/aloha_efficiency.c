#समावेश <stdio.h>
#समावेश <math.h>
/* medium access control: throughput of pure and slotted ALOHA, and the load at which each peaks */
पूर्णांक मुख्य(व्योम) {
  द्विगुन best_pure = 0, best_slotted = 0, load_pure = 0, load_slotted = 0;
  क्रम (द्विगुन load = 0.05; load <= 2.0; load += 0.05) {
    द्विगुन pure = load * exp(-2 * load), slotted = load * exp(-load);
    अगर (pure > best_pure) { best_pure = pure; load_pure = load; }
    अगर (slotted > best_slotted) { best_slotted = slotted; load_slotted = load; }
  }
  म_लिखो("pure %.3f at %.2f, slotted %.3f at %.2f\n", best_pure, load_pure, best_slotted, load_slotted);
  वापस 0;
}
