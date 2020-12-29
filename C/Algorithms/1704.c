#include <stdbool.h>
#include <string.h>

bool halvesAreAlike(char *s) {
  int len = strlen(s) - 1;
  int mid = (len / 2) + 1, count = 0;
  char *vowels = "aAoOuUiIeE", *runner;
  // Go through first part.
  while (mid--) {
    runner = vowels;
    while (*runner) {
      if (*s == *runner++) {
        count++;
        break;
      }
    }
    s++;
  }
  // Continue until the end.
  while (*s) {
    runner = vowels;
    while (*runner) {
      if (*s == *runner++) {
        count--;
        if (count < 0)
          return 0;
        break;
      }
    }
    s++;
  }
  return count == 0;
}
