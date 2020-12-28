int specialArray(int *nums, int numsSize) {
  for (int i = 1; i < numsSize + 1; i++) {
    int match = 0;
    for (int j = 0; j < numsSize; j++) {
      int el = nums[j];
      if (el >= i) {
        match++;
        if (match > i)
          break;
        continue;
      }
      // break if num of elements left to see
      if (match + (numsSize - j) < i)
        break;
    }
    if (match == i)
      return i;
  }
  return -1;
}
