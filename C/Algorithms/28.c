int strStr(char *haystack, char *needle) {
  if (!*needle)
    return 0;
  int lenh = strlen(haystack), lenn = strlen(needle);
  if (lenn > lenh)
    return -1;

  int diff = lenh - lenn;
  for (int i = 0; i < lenh; i++) {
    if (i <= diff) {
      bool found = true;
      for (int j = 0; j < lenn; j++) {
        if (haystack[i + j] != needle[j]) {
          found = false;
          break;
        }
      }
      if (found)
        return i;
    }
  }
  return -1;
}