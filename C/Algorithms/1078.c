#include <stdlib.h>
#include <string.h>

#define MATCH(src, str, flag)                                                  \
  while (*src && *str) {                                                       \
    if (*src++ != *str++) {                                                    \
      while (*src && *src != ' ')                                              \
        src++;                                                                 \
      flag = 1;                                                                \
      break;                                                                   \
    }                                                                          \
  }                                                                            \
  if (*src) {                                                                  \
    src++;                                                                     \
  } else {                                                                     \
    break;                                                                     \
  }

#define MAYBE_REALLOC(ptr, size, length)                                       \
  if (length + 1 >= size) {                                                    \
    size = size * 1.5;                                                         \
    ptr = realloc(ptr, size * sizeof(*ptr));                                   \
  }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findOcurrences(char *text, char *first, char *second, int *returnSize) {
  int size = 5, length = 0, bail = 0;
  char **result = malloc(size * sizeof(*result));
  char *rfirst, *rsecond, *pin;
  while (*text) {
    rfirst = first, rsecond = second, bail = 0;
    // Match the first string.
    MATCH(text, rfirst, bail);
    // bail if necessary.
    if (bail)
      continue;
    bail = 0;

    // Keep track of where we are and match next.
    pin = text;
    MATCH(text, rsecond, bail);
    // bail but backtrack.
    if (bail) {
      text = pin;
      continue;
    }

    // We've matched second, grab third word
    pin = text;
    while (*text && *text != ' ')
      text++;
    int diff = (text - pin) + 1;
    // Place in result (check for realloc!)
    MAYBE_REALLOC(result, size, length);
    result[length] = malloc(diff * sizeof(**result));
    strncpy(result[length], pin, diff - 1);
    result[length++][diff - 1] = '\0';
    // Unconditionally go back.
    text = pin;
  }

  *returnSize = length;
  return result;
}
