int searchInsert(int *nums, int numsSize, int target) {
  int start = 0, end = numsSize;
  while (start < end) {
    int mid = (start + end) >> 1;
    if (nums[mid] < target)
      start = mid + 1;
    else
      end = mid;
  }
  return start;
}