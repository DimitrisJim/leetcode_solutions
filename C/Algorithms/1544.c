#include <stdlib.h>
#include <string.h>

#define ABS(x) x > 0 ? x : -x

char *makeGood(char *s) {
  // Make buffer at least as long as s.
  char *res = malloc(strlen(s) + 1);
  int resLen = 0;

  while (*s && *(s + 1)) {
    int diff = *s - *(s + 1);
    diff = ABS(diff);
    if (diff == 32) {
      s = (s + 2);
      while (*s && resLen > 0) {
        diff = *s - *(res - 1);
        diff = ABS(diff);
        if (diff == 32) {
          res--;
          s++;
          resLen--;
        } else
          break;
      }
    } else {
      // Add to res.
      *res++ = *s++;
      resLen++;
    }
  }
  if (*s) {
    *res++ = *s++;
    resLen++;
  }
  *res = '\0';
  return res - resLen;
}
