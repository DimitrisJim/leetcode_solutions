#include <math.h>
#include <string.h>

int titleToNumber(char *s) {
  int col = 0, i = strlen(s) - 1;
  while (*s)
    col += (*s++ - 64) * pow(26, i--);
  return col;
}
