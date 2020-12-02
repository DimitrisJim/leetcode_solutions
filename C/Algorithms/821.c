#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *shortestToChar(char *S, char C, int *returnSize) {
  *returnSize = strlen(S);
  int *result = malloc(*returnSize * sizeof(*result)), prev_pos = -1,
      length = 0;

  for (int pos = 0; *S; S++, pos++) {
    if (*S == C) {
      if (prev_pos == -1) {
        // Add distances from pos until 0.
        for (int i = pos; i >= 0; i--)
          result[length++] = i;
      } else {
        int diff = pos - prev_pos;
        int middle = diff / 2;
        for (int i = 1; i < middle + (diff % 2) ? 1 : 0; i++)
          result[length++] = i;
        for (int i = middle; i >= 0; i--)
          result[length++] = i;
      }
      prev_pos = pos;
    }
  }
  if (prev_pos != *returnSize) {
    int diff = *returnSize - prev_pos;
    for (int i = 1; i < diff; i++)
      result[length++] = i;
  }
  return result;
}
