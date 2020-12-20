#include "uthash/src/uthash.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *value;
  UT_hash_handle hh;
} s_entry;

// S into set S of unique words in S and set Seen of words non-unique in S.
void make_uniques(char *S, s_entry **Set, s_entry **Seen) {
  while (*S) {
    // start points to start, S to end. (of word)
    char *start = S, *word;
    while (*S && *S != ' ')
      S++;
    ptrdiff_t diff = S - start;
    word = malloc(diff + 1);
    strncpy(word, start, diff);
    word[diff] = '\0';

    // Add to seen and set. if we see it again, remove from
    // set.
    s_entry *e;
    HASH_FIND(hh, *Seen, word, diff + 1, e);
    if (!e) {
      e = malloc(sizeof(*e));
      // Note: Now responsible for free-ing it.
      e->value = word;
      HASH_ADD_KEYPTR(hh, *Seen, e->value, diff + 1, e);
      // Add to Set of uniques too.
      s_entry *e2 = malloc(sizeof(*e2));
      e2->value = word;
      HASH_ADD_KEYPTR(hh, *Set, e2->value, diff + 1, e2);
    } else {
      if (*Set) {
        s_entry *u;
        HASH_FIND(hh, *Set, e->value, strlen(e->value) + 1, u);
        if (u)
          HASH_DEL(*Set, u);
      }
    }
    // Advance past space.
    if (*S)
      S++;
  }
}

// Creates the difference between A and B.
// Clears the Sets passed in.
s_entry *difference(s_entry **A, s_entry **B) {
  s_entry *result = NULL, *cur, *tmp;

  // For each element of A, add to result if not in B.
  HASH_ITER(hh, *A, cur, tmp) {
    s_entry *e;
    int len = strlen(cur->value) + 1;
    HASH_FIND(hh, *B, cur->value, len, e);
    if (!e) {
      HASH_ADD_KEYPTR(hh, result, cur->value, len, cur);
    } else {
      HASH_DEL(*A, cur);
    }
  }
  return result;
}

// Creates the union between the differences between A and B.
s_entry *unite(s_entry **A, s_entry **B) {
  s_entry *result = difference(A, B), *tmp = difference(B, A), *cur, *t;
  HASH_ITER(hh, tmp, cur, t) {
    s_entry *e;
    int len = strlen(cur->value) + 1;
    HASH_FIND(hh, result, cur->value, len, e);
    if (!e) {
      HASH_ADD_KEYPTR(hh, result, cur->value, len, cur);
    } else {
      HASH_DEL(tmp, cur);
    }
  }
  return result;
}

char **to_array(s_entry **S, int size) {
  char **result = malloc(size * sizeof(*result));
  s_entry *cur, *tmp;
  int i = 0;
  HASH_ITER(hh, *S, cur, tmp) {
    int length = strlen(cur->value) + 1;
    result[i] = malloc(length);
    strncpy(result[i++], cur->value, length);

    // Free up stuff.
    HASH_DEL(*S, cur);
  }
  return result;
}

void set_del(s_entry **s) {
  s_entry *cur, *tmp;
  HASH_ITER(hh, *s, cur, tmp) {
    HASH_DEL(*s, cur);
    free(cur->value);
    free(cur);
  }
}

// Note: The returned array must be malloced, assume caller calls free().
char **uncommonFromSentences(char *A, char *B, int *returnSize) {
  s_entry *sA = NULL, *seenA = NULL, *sB = NULL, *seenB = NULL;
  // Create sets of seen and uniques.
  make_uniques(A, &sA, &seenA);
  make_uniques(B, &sB, &seenB);

  // Get differences.
  s_entry *diffA = difference(&sA, &seenB), *diffB = difference(&sB, &seenA);
  // and unite them.
  s_entry *sRes = unite(&diffA, &diffB);

  // and get as array.
  *returnSize = HASH_COUNT(sRes);
  char **res = to_array(&sRes, *returnSize);

  // I feel like I'm still leaking stuff. This is flimsy.
  set_del(&sRes);
  set_del(&seenA);
  set_del(&seenB);
  return res;
}
