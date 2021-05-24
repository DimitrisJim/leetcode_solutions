int compare(const void *x, const void *y) {
  const int(*a)[2] = x;
  const int(*b)[2] = y;
  // Sort by sum of each sub-array.
  return ((*a)[1] > (*b)[1]) - ((*a)[1] < (*b)[1]);
}

bool containsNearbyAlmostDuplicate(int *nums, int numsSize, int k, int t) {
  int(*snums)[2] = malloc(sizeof(int[numsSize][2]));

  for (int i = 0; i < numsSize; i++) {
    snums[i][0] = i;
    snums[i][1] = nums[i];
  }
  qsort(snums, numsSize, sizeof snums[0], compare);

  for (int i = 0; i < numsSize; i++) {
    int j = i + 1;
    while (j < numsSize && (long)snums[j][1] - (long)snums[i][1] <= t) {
      int diff = snums[i][0] - snums[j][0];
      if (diff < 0)
        diff = -diff;
      if (diff <= k)
        return true;
      j++;
    }
  }
  return false;
}