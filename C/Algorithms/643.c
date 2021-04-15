double findMaxAverage(int *nums, int numsSize, int k) {
  int limit = k - 1;
  double partial_avg = 0., max_avg = -1.7976931348623158e+10;

  // Get avg until k-1
  for (int i = 0; i < limit; i++) {
    partial_avg += (double)nums[i] / k;
  }

  double candidate, last;
  for (int i = limit; i < numsSize; i++) {
    last = (double)nums[i] / k;
    candidate = partial_avg + last;
    if (candidate > max_avg)
      max_avg = candidate;
    // Update partial_avg by removing first term and
    // adding last term (nums[i] / k)
    partial_avg += (last - (double)nums[i - limit] / k);
  }
  return max_avg;
}