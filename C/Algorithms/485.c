int findMaxConsecutiveOnes(int *nums, int numsSize) {
  int max = 0, count = 0;
  while (numsSize--) {
    if (*nums++) {
      count++;
      if (count > max)
        max = count;
      continue;
    }
    count = 0;
  }
  return max;
}
