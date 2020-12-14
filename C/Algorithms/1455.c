int isPrefixOfWord(char *sentence, char *searchWord) {
  int idx = 1, try = 1;
  char *runner = searchWord;
  while (*sentence) {
    while (*sentence && *runner && try) {
      if (*sentence != *runner) {
        try = 0;
      } else {
        sentence++, runner++;
      }
    }
    if (!*runner)
      return idx;
    // advance index and make runner
    // point to start of searchWord again.
    if (*sentence == ' ') {
      idx++;
      runner = searchWord;
      try = 1;
    }
    sentence++;
  }
  return -1;
}
