int singleNumber(int *nums, int numsSize) {
  int accumulator = 0;
  while (numsSize--)
    accumulator ^= *nums++;
  return accumulator;
}
