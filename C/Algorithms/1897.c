bool makeEqual(char **words, int wordsSize) {
  // Build count of characters.
  int charCount[26] = {0};
  for (int i = 0; i < wordsSize; i++) {
    char *word = words[i];
    while (*word)
      charCount[*word++ - 97]++;
  }
  // Assert that we can distribute these evenly (char count % length == 0)
  for (int i = 0; i < 26; i++) {
    if (charCount[i] % wordsSize)
      return false;
  }
  return true;
}