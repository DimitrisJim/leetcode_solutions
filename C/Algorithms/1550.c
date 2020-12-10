#include <stdbool.h>

bool threeConsecutiveOdds(int *arr, int arrSize) {
  int count = 0;
  for (int i = 0; i < arrSize; i++) {
    count = *(arr + i) & 1 ? count + 1 : 0;
    if (count == 3)
      return true;
  }
  return false;
}
