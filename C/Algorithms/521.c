#include <string.h>

int findLUSlength(char *a, char *b) {
  int same = 1, count = 0;
  while (*a || *b) {
    if (!*b) {
      return count + strlen(a);
    } else if (!*a) {
      return count + strlen(b);
    }
    if (*a++ != *b++)
      same = 0;
    count++;
  }
  return same ? -same : count;
}
