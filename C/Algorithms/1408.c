#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Comparator uses their sizes.
int cmpcp(const void *x, const void *y) {
  int a = strlen(*(const char **)x);
  int b = strlen(*(const char **)y);

  return (a > b) - (a < b);
}

// Return true if word1 is substring of word2, don't mess pointer positions.
bool contains(char *word2, char *word1) {
  while (*word2) {
    char *runner2 = word2, *runner1 = word1;
    while (*runner2 && *runner1 && *runner2++ == *runner1++) {
      if (!*runner1)
        return true;
    }
    word2++;
  }
  return false;
}

// Note: The returned array must be malloced, assume caller calls free().
char **stringMatching(char **words, int wordsSize, int *returnSize) {
  int size = 5, length = 0;
  char **result = malloc(size * sizeof(*result));
  qsort(words, wordsSize, sizeof(*words), cmpcp);

  for (int i = 0; i < wordsSize; i++) {
    char *word1 = words[i];
    for (int j = i + 1; j < wordsSize; j++) {
      char *word2 = words[j];
      if (contains(word2, word1)) {
        // If necessary, resize.
        if (length + 1 == size) {
          size *= 1.5;
          result = realloc(result, size * sizeof(*result));
        }

        // Copy string over.
        int slen = strlen(word1) + 1;
        result[length] = malloc(slen);
        strncpy(result[length++], word1, slen);

        // No double-adds.
        break;
      }
    }
  }
  // Set size and return.
  *returnSize = length;
  return result;
}
