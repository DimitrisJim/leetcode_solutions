#include <stdlib.h>
#include <string.h>

int cmps(const void *x, const void *y) {
  const char *a = *(const char **)x;
  const char *b = *(const char **)y;

  // Go until first space.
  int fs_a = 0, fs_b = 0;
  while (*a && *a++ != ' ')
    fs_a++;
  while (*b && *b++ != ' ')
    fs_b++;

  // Have been advanced past first space, we're now
  // comparing char * past identifier.
  int cmp = strcmp(a, b);

  // Identifier is used as tiebracker. Compare first
  // min(fs_a, fs_b) characters to discern order if
  // cmp is zero.
  return cmp != 0 ? cmp
                  : -strncmp(a - fs_a, b - fs_b, fs_a > fs_b ? fs_b : fs_a);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **reorderLogFiles(char **logs, int logsSize, int *returnSize) {
  // assume 50/50 split for sizes, initially.
  int dsize = logsSize / 2, lsize = logsSize / 2, dlen = 0, llen = 0;
  char **digits = malloc(dsize * sizeof(*digits)),
       **letters = malloc(dsize * sizeof(*letters));

  // Copy digit rows in digits, letter rows in letters.
  for (int i = 0; i < logsSize; i++) {
    char *log = *(logs + i);
    // Advance until first space and check value of
    // first character encountered.
    while (*log && *log++ != ' ')
      ;
    if (*log > 57) {
      if (llen + 1 == lsize) {
        lsize *= lsize * 1.5;
        letters = realloc(letters, lsize * sizeof(*letters));
      }
      letters[llen++] = logs[i];
    } else {
      if (dlen + 1 == dsize) {
        dsize *= dsize * 1.5;
        digits = realloc(digits, dsize * sizeof(*digits));
      }
      digits[dlen++] = logs[i];
    }
  }
  // Need to sort letters array to bring rows in order.
  qsort(letters, llen, sizeof(*letters), cmps);

  // Now copy *pointers* over after resizing letters to fit elements
  // in digits. (Apparently, I can just copy pointers and
  // there's no need to malloc and memcpy.)
  int length = llen + dlen;
  letters = realloc(letters, length * sizeof(*letters));
  for (int i = llen, j = 0; i < length; i++, j++) {
    *(letters + i) = *(digits + j);
  }
  // Clean up and return.
  free(digits);
  *returnSize = length;
  return letters;
}
