int icmp(const void *x, const void *y) {
  int a = *(const int *)x;
  int b = *(const int *)y;

  return (a > b) - (a < b);
}

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
  // Copy elements from nums2 into nums1.
  for (int i = 0; i < n; i++) {
    *(nums1 + m + i) = *(nums2 + i);
  }
  // Sort nums1
  qsort(nums1, nums1Size, sizeof(*nums1), icmp);
}