#include <string.h>

int countMatches(char ***items, int itemsSize, int *itemsColSize, char *ruleKey,
                 char *ruleValue) {
  int index = 0;
  if (strcmp(ruleKey, "color") == 0)
    index = 1;
  else if (strcmp(ruleKey, "name") == 0)
    index = 2;

  int count = 0;
  for (int i = 0; i < itemsSize; i++) {
    if (strcmp(items[i][index], ruleValue) == 0)
      count++;
  }
  return count;
}
