#include <stdbool.h>

bool hasAlternatingBits(int n) {
  while (n) {
    int b = n & 1;
    n >>= 1;
    if (b == (n & 1)) {
      return false;
    }
  }
  return true;
}
