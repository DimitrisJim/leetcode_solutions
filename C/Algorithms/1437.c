bool kLengthApart(int *nums, int numsSize, int k) {
  int diff = k, start = 0;
  for (int i = 0; i < numsSize; i++) {
    if (*(nums + i)) {
      start = i + 1;
      break;
    }
  }
  for (; start < numsSize; start++) {
    if (*(nums + start)) {
      if (diff > 0)
        return false;
      diff = k;
    } else
      diff--;
  }

  return true;
}