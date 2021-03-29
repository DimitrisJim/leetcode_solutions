char *mergeAlternately(char *word1, char *word2) {
  int size1 = strlen(word1), size2 = strlen(word2);
  // Allocate max + 1 bytes
  char *result = malloc(size1 + size2 + 1), *runner;
  runner = result;
  // Interleave the first.
  char *control = (size1 > size2) ? word2 : word1;
  while (*control++) {
    *runner++ = *word1++;
    *runner++ = *word2++;
  }

  // Add the rest
  char *max = (size1 > size2) ? word1 : word2;
  while (*max)
    *runner++ = *max++;
  *runner = '\0';
  return result;
}
