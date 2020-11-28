#include <stdlib.h>
#include <string.h>

char *removeDuplicates(char *S) {
  int length = 0, size = 20;
  char *res = malloc(size);
  while (*S) {
    if ((length >= 1) && res[length - 1] == *S) {
      length--;
      S++;
    } else {
      if (length == size - 1) {
        size *= 1.5;
        res = realloc(res, size);
      }
      *(res + length++) = *S++;
    }
  }
  *(res + length) = '\0';
  return res;
}
