bool canBeIncreasing(int *nums, int numsSize) {
  bool removed = false;
  int i = 0, end = numsSize - 1;
  while (i < end) {
    int a = nums[i], b = nums[i + 1];
    if (a >= b) {
      // if we've removed before, return.
      if (removed)
        return false;
      removed = !removed;
      // Need to check neighbours of a, b.
      // if b <= than neighbour of a, b is the
      // odd one out and should be removed.
      if (i > 0 && b <= nums[i - 1]) {
        // but if a is larger than neighbour of
        // b, there's nothing we can do.
        if (i + 2 < numsSize && a >= nums[i + 2])
          return false;
        i += 2;
        continue;
      }
    }
    i++;
  }
  return true;
}