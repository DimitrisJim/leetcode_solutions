#define IS_VOWEL(x)                                                            \
  (x == 97 || x == 101 || x == 105 || x == 111 || x == 117 || x == 65 ||       \
   x == 69 || x == 73 || x == 79 || x == 85)

char *reverseVowels(char *s) {
  int start = 0, end = 0;
  char *runner = s;
  while (*runner++)
    end++;
  while (end > start) {
    while (end > start && !IS_VOWEL(*(s + end)))
      end--;
    while (end > start && !IS_VOWEL(*(s + start)))
      start++;

    // swap
    char tmp = s[end];
    s[end--] = s[start];
    s[start++] = tmp;
  }
  return s;
}