bool areOccurrencesEqual(char *s) {
  int *freqs = calloc(26, sizeof(*freqs));

  // hold on to first valid char and count frequencies.
  int f = *s - 97;
  while (*s)
    freqs[*s++ - 97]++;

  // check that all non zero values are equal to target.
  int target = freqs[f];
  for (int i = 0; i < 26; i++) {
    if (freqs[i] != 0) {
      if (freqs[i] != target)
        return false;
    }
  }
  return true;
}