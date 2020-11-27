#include <stdbool.h>

bool arrayStringsAreEqual(char **word1, int word1Size, char **word2,
                          int word2Size) {
  int i = 0, j = 0;
  char *w1 = *(word1 + i), *w2 = *(word2 + j);
  while (1) {
    if (*w1 == '\0') {
      if (i < word1Size - 1)
        w1 = *(word1 + (++i));
      else
        break;
    }
    if (*w2 == '\0') {
      if (j < word2Size - 1)
        w2 = *(word2 + (++j));
      else
        break;
    }
    // Check characters
    if (*w1++ != *w2++)
      return false;
  }
  // Check that we've have reached the end of the words when we break.
  if (*w1 || *w2)
    return false;
  // Check that there's no left over words.
  return (i == word1Size - 1) && (j == word2Size - 1);
}
