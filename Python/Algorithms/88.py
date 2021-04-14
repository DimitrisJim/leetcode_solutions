class Solution:
    def merge(self, nums1, m: int, nums2, n: int) -> None:
        nums1[m:] = nums2
        nums1.sort()