#include <stdlib.h>

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
  int i = 0, j = numbersSize - 1;
  while (i < j) {
    int ts = numbers[i] + numbers[j];
    if (ts == target)
      break;
    ts > target ? j-- : i++;
  }
  *returnSize = 2;
  int *ret = malloc(2 * sizeof(*ret));
  ret[0] = i + 1;
  ret[1] = j + 1;
  return ret;
}
