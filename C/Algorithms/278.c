// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
  uint start = 0, end = n;
  while (end - start != 1) {
    int mid = (start + end) / 2;
    if (isBadVersion(mid))
      end = mid;
    else
      start = mid;
  }
  return end;
}