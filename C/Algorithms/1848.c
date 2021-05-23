#define MIN(x, y) (x) < (y) ? (x) : (y)

int getMinDistance(int *nums, int numsSize, int target, int start) {
  int min = numsSize;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == target) {
      int diff = start - i;
      diff = diff < 0 ? -diff : diff;
      min = MIN(min, diff);
    }
  }
  return min;
}