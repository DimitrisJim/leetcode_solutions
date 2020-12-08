#include <string.h>

char *interpret(char *s) {
  int length = strlen(s), i = 0, cur = 0;

  while (i < length) {
    // () case
    if ((*(s + i) == '(') && (*(s + i + 1) == ')')) {
      *(s + cur++) = 'o';
      i = i + 2;
    } else if (*(s + i) == 'G') {
      s[cur++] = 'G';
      i++;
    }
    // case (al)
    else {
      *(s + cur++) = 'a';
      *(s + cur++) = 'l';
      i = i + 4;
    }
  }
  *(s + cur) = '\0';
  return s;
}
