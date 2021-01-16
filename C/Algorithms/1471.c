#include <stdlib.h>
#include <string.h>

char *reformat(char *s) {
  int slen = strlen(s), charslen = 0, numslen = 0;
  int limit = slen / 2 + 1;
  char *chars = malloc(limit + 1), *nums = malloc(limit + 1), *runner = s;

  while (*runner) {
    char ch = *runner++;
    // Note: both must fall within limits.
    if ((ch - 48) < 10) {
      if (numslen == limit) {
        free(chars), free(nums);
        return "";
      }
      nums[numslen++] = ch;
    } else {
      if (charslen == limit) {
        free(chars), free(nums);
        return "";
      }
      chars[charslen++] = ch;
    }
  }
  nums[numslen] = '\0';
  chars[charslen] = '\0';
  int diff = charslen - numslen;
  runner = s;
  if (diff == 0) {
    // Perfect split.
    while (*s) {
      *s++ = *chars++;
      *s++ = *nums++;
    }
  } else if (diff == 1) {
    // Chars has 1 char more.
    *s++ = *chars++;
    while (*s) {
      *s++ = *nums++;
      *s++ = *chars++;
    }
  } else if (diff == -1) {
    *s++ = *nums++;
    while (*s) {
      *s++ = *chars++;
      *s++ = *nums++;
    }
  } else {
    // Shouldn't actually occur here.
    free(chars), free(nums);
    return "";
  }
  free(chars - charslen), free(nums - numslen);
  return runner;
}
