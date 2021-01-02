#include <stdlib.h>

char slowestKey(int *releaseTimes, int releaseTimesSize, char *keysPressed) {
  int max = releaseTimes[0], size = 5, length = 0;
  int *max_indices = malloc(size * sizeof(*max_indices));
  max_indices[length++] = 0;

  for (int i = 1; i < releaseTimesSize; i++) {
    int diff = *(releaseTimes + i) - *(releaseTimes + i - 1);
    if (diff > max) {
      length = 0;
      *(max_indices + length++) = i;
      max = diff;
    } else if (diff == max) {
      // reallocate if necessary.
      if (length == size - 1) {
        size *= 1.5;
        max_indices = realloc(max_indices, size * sizeof(*max_indices));
      }
      *(max_indices + length++) = i;
    }
  }

  char maxC = *(keysPressed + *(max_indices + 0));
  for (int i = 0; i < length; i++) {
    char c = *(keysPressed + *(max_indices + i));
    if (c > maxC)
      maxC = c;
  }
  free(max_indices);
  return maxC;
}
