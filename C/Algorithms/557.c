#include <stdio.h>

// Thanks, wiki: https://en.wikipedia.org/wiki/XOR_swap_algorithm
#define XORSWAP_UNSAFE(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))

#define XORSWAP(a, b) ((&(a) == &(b)) ? (a) : XORSWAP_UNSAFE(a, b))

char *reverseWords(char *s) {
  int s_start = 0;
  for (int i = 0;; i++) {
    // Switch characters around only if we encounter
    // a space or the NULL character.
    if ((*(s + i) == '\0') || (*(s + i) == ' ')) {
      // Grab midpoint and switch around it.
      int mid = (i + s_start) / 2;
      for (int j = i - 1; j >= mid; j--, s_start++) {
        XORSWAP(*(s + j), *(s + s_start));
      }
      s_start = i + 1;
      // We entered because we encountered the null character,
      // so we've got to bail now.
      if (*(s + i) == '\0')
        break;
    }
  }
  return s;
}

int main(int argc, char *argv[]) {
  char s[] = "Let's take LeetCode contest";
  printf("%s \n", reverseWords(s));
  return 0;
}
