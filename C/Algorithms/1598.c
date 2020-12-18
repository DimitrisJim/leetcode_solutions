#include <string.h>

int minOperations(char **logs, int logsSize) {
  int in_main = 1, depth = 0;
  while (logsSize--) {
    char *log = *logs++;
    if (strcmp(log, "../") == 0) {
      if (in_main == 0) {
        depth--;
        if (!depth)
          in_main = 1;
      }
    } else if (strcmp(log, "./") == 0) {
      continue;
    } else {
      depth++;
      if (in_main)
        in_main ^= 1;
    }
  }
  return depth;
}
