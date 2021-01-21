#include <stdbool.h>

bool canConstruct(char *ransomNote, char *magazine) {
  int letters[26] = {0};

  // Fill up with counts.
  while (*magazine)
    letters[*magazine++ - 97]++;

  // Go through and reduce counts.
  // If at any point count == 0 (and we have encountered value)
  // in ransomNote, bail.
  while (*ransomNote) {
    int idx = *ransomNote++ - 97;
    if (letters[idx]-- == 0)
      return false;
  }
  return true;
}
