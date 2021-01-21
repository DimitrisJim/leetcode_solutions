#include <stdbool.h>

#define UPPER(x) ((int)x <= 90)
#define LOWER(x) ((int)x > 96)

bool detectCapitalUse(char *word) {
  if (!*(word + 1))
    return true;

  int upper = 0;
  if (UPPER(*word)) {
    if (UPPER(*(word + 1))) {
      upper = 1;
    } else {
      // Advance word
      word++;
    }
  }
  // Basically all.
  while (*word) {
    if (upper) {
      if (!UPPER(*word++))
        return false;
    } else {
      if (!LOWER(*word++))
        return false;
    }
  }
  return true;
}
