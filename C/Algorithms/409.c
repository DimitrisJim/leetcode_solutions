#define CHARS 58

int longestPalindrome(char *s) {
  // Build a count of letters (note, need extra space because some
  // non-letter chars follow uppercase ones.)
  int letters[CHARS] = {0};
  while (*s) {
    letters[*s++ - 65]++;
  }

  int length = 0, add = 0;
  for (int i = 0; i < CHARS; i++) {
    int count = letters[i];
    if (count & 1) {
      add = 1;
      length--;
    }
    length += count;
  }
  return length + add;
}