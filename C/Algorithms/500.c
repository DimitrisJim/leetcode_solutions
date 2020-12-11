#include "ctype.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "uthash/src/uthash.h"

#define NUM_ROWS 3
#define MAYBE_REALLOC(ptr, size, length)                                       \
  if (length + 1 >= size) {                                                    \
    size *= 2;                                                                 \
    ptr = realloc(ptr, size * (sizeof(*ptr)));                                 \
  }

typedef struct {
  int key;
  UT_hash_handle hh;
} s_entry;

// Keep rows in uppercase.
const char *KROWS[NUM_ROWS] = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};

// Make a set out of each row in KROWS.
void make_row(s_entry **s, const char *row) {
  char c;
  while ((c = *row++)) {
    // We know we have distinct characters.
    s_entry *e = malloc(sizeof(*e));
    e->key = (int)c;
    HASH_ADD_INT(*s, key, e);
  }
}

// Returns true if all chars in word are contained in set, else false.
bool contains_word(char *word, int wordLength, s_entry **set) {
  // Yes, making word into string would reduce time.
  for (int i = 0; i < wordLength; i++) {
    // make uppercase, first
    int c = toupper(word[i]);
    s_entry *e;
    HASH_FIND_INT(*set, &c, e);
    if (!e)
      return false;
  }
  return true;
}

char **findWords(char **words, int wordsSize, int *returnSize) {
  // Build sets of rows.
  s_entry *rows[NUM_ROWS] = {NULL};
  for (int i = 0; i < NUM_ROWS; i++) {
    make_row(&rows[i], KROWS[i]);
  }

  int size = (wordsSize / 3) + 1, length = 0;
  char **result = malloc(size * sizeof(*result));
  for (int i = 0; i < wordsSize; i++) {
    char *word = words[i];
    for (int j = 0; j < NUM_ROWS; j++) {
      // Check if word is contained in any of the sets.
      int wlen = strlen(word);
      if (contains_word(word, wlen, &rows[j])) {
        // We have a match, copy over.
        MAYBE_REALLOC(result, size, length);
        result[length] = malloc(wlen + 1);
        strncpy(result[length++], word, wlen + 1);
      }
    }
  }
  // Finish up.
  for (int i = 0; i < NUM_ROWS; i++) {
    HASH_CLEAR(hh, rows[i]);
  }
  *returnSize = length;
  return result;
}
