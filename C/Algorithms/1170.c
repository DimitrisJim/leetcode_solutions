#include "uthash/src/uthash.h"
#include <stdlib.h>
#include <string.h>

// Uthash structure.
typedef struct {
  int key;
  int value;
  UT_hash_handle hh;
} d_entry;

// Compare function for chars.
int cmpc(const void *x, const void *y) {
  char a = *(const char *)x;
  char b = *(const char *)y;

  return (a > b) - (a < b);
}

// Compare function for ints.
int cmpi(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (a > b) - (a < b);
}

// Frequency of smallest char in s.
inline int frequency(char *s) {
  int length = strlen(s), count = 1;
  qsort(s, length, sizeof(*s), cmpc);
  for (int i = 1; i < length; i++) {
    if (s[i - 1] != s[i])
      return count;
    count++;
  }
  return count;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *numSmallerByFrequency(char **queries, int queriesSize, char **words,
                           int wordsSize, int *returnSize) {
  // Initialize word frequencies array and sort it.
  int *word_frequencies = malloc(wordsSize * sizeof(*word_frequencies));
  for (int i = 0; i < wordsSize; i++)
    word_frequencies[i] = frequency(words[i]);
  qsort(word_frequencies, wordsSize, sizeof(*word_frequencies), cmpi);

  // Keep cache of querie[i] frequency to number
  // of words for which freq query[i] < freq word.
  d_entry *cache = NULL;
  int *result = malloc(queriesSize * sizeof(*result));

  // Go through all queries.
  for (int i = 0; i < queriesSize; i++) {
    int freq = frequency(queries[i]);
    // Check if freq is present in cache:
    d_entry *d;
    HASH_FIND_INT(cache, &freq, d);
    // is not, add it.
    if (!d) {
      for (int j = 0; j < wordsSize; j++) {
        if (freq < word_frequencies[j]) {
          d = malloc(sizeof(*d));
          d->key = freq;
          d->value = wordsSize - j;
          HASH_ADD_INT(cache, key, d);
          break;
        }
      }
      // No word freq is larger than freq for query[i].
      if (!d) {
        d = malloc(sizeof(*d));
        d->key = freq;
        d->value = 0;
        HASH_ADD_INT(cache, key, d);
      }
    }
    // After initializing d, set result[i] to value of d.
    result[i] = d->value;
  }
  // Clean these up.
  HASH_CLEAR(hh, cache);
  free(word_frequencies);
  // and return.
  *returnSize = queriesSize;
  return result;
}
