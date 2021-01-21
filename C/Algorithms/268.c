int missingNumber(int *nums, int numsSize) {
  // One distinct number, so, we can also xor in
  // all the numbers in the range and after xoring
  // with the numbers in nums, the unique element will
  // be the only one left (since it doesn't exist in
  // nums in order for it to be xore'd out.)
  int missing = 0;
  for (int i = 0; i < numsSize; i++)
    missing ^= (i + 1) ^ *(nums + i);
  return missing;
}
