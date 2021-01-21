int search(int *nums, int numsSize, int target) {
  int start = 0, end = numsSize - 1, mid, idx;
  while (start <= end) {
    idx = (start + end) / 2;
    mid = *(nums + idx);
    if (mid == target)
      return idx;
    // go left
    if (target < mid)
      end = idx - 1;
    else
      start = idx + 1;
  }
  return -1;
}
