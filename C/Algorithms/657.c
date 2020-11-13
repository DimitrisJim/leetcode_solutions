#include <stdbool.h>

bool judgeCircle(char *moves) {
  int u = 0, d = 0, l = 0, r = 0;
  while (*moves) {
    switch (*moves++) {
    case 'L':
      l++;
      break;
    case 'R':
      r++;
      break;
    case 'U':
      u++;
      break;
    case 'D':
      d++;
      break;
    }
  }
  return (u == d) && (l == r);
}
