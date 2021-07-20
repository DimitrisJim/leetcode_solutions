char *longestCommonPrefix(char **strs, int strsSize) {
  char *prefix = strs[0];
  for (int i = 1; i < strsSize; i++) {
    char *s = strs[i], *runner = prefix;

    int i = 0;
    while (*s && *runner && *s++ == *runner++)
      i++;
    if (i == 0) {
      return "";
    }
    prefix[i] = '\0';
  }
  return prefix;
}