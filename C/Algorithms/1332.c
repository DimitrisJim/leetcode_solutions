int removePalindromeSub(char *s) {
  int len = strlen(s);
  if (len == 0)
    return 0;

  // Check if full string is palindrome:
  int start = 0, end = len - 1;
  while (end - start > 1) {
    if (s[start] != s[end])
      break;
    start++, end--;
  }
  if (end - start <= 1)
    return 1;
  // Check if we have both 'a's and 'b's
  char c = s[0];
  for (int i = 0; i < len; i++) {
    if (s[i] != c)
      return 2;
  }
  return 1;
}
