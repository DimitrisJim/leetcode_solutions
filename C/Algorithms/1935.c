int canBeTypedWords(char *text, char *brokenLetters) {
  // Doesn't look that clean to me.
  int count = 0;
  int *chars = calloc(26, sizeof(chars));
  while (*brokenLetters) {
    chars[*brokenLetters++ - 97] = 1;
  }
  while (*text) {
    while (*text && *text != ' ') {
      if (chars[*text++ - 97]) {
        count--;
        break;
      }
    }
    while (*text && *text != ' ')
      text++;
    if (*text)
      text++;
    count++;
  }
  return count;
}