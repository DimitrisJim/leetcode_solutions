static char letters[52] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

char *reverseOnlyLetters(char *S) {
  int start = 0, end = strlen(S) - 1, flagDone = 0;
  while (start < end) {
    while (1) {
      if (start == end)
        return S;
      for (int i = 0; i < 52; i++) {
        if (S[start] == letters[i]) {
          flagDone = 1;
          break;
        }
      }
      if (flagDone) {
        flagDone = 0;
        break;
      }
      start++;
    }

    while (1) {
      if (start == end)
        return S;
      for (int i = 0; i < 52; i++) {
        if (S[end] == letters[i]) {
          flagDone = 1;
          break;
        }
      }
      if (flagDone) {
        flagDone = 0;
        break;
      }
      end--;
    }
    char tmp = S[start];
    S[start] = S[end];
    S[end] = tmp;
    start++, end--;
  }
  return S;
}
