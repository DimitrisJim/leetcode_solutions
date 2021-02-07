#include <stdbool.h>

bool check(int *nums, int numsSize) {
  int start = nums[0];
  for (int i = 1; i < numsSize; i++) {
    // posible point of rotation
    if (nums[i - 1] > nums[i]) {
      for (int j = i + 1; j < numsSize; j++) {
        // Make sure we still have non-decreasing order
        // and none are larger than start (which would
        // mean that before rotation, nums[i-1] < nums[i] for
        // nums[i-1] == start.)
        if (nums[j - 1] > nums[j] || start < nums[j])
          return false;
      }
    }
  }
  return true;
}
