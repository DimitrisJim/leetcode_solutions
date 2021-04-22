int removeElement(int *nums, int numsSize, int val) {
  int start = 0, finish = numsSize;
  while (start < finish) {
    if (nums[start] == val) {
      // remove end element and replace if
      // there's still space.
      int end = nums[--finish];
      if (start < finish) {
        nums[start] = end;
      }
    } else {
      start++;
    }
  }
  return finish;
}