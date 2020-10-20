class Solution:
    def maxProduct(self, nums):
        """ O(1) space, O(N) time. """
        i = max(nums)   # O(N)
        nums.remove(i)  # O(N)
        j = max(nums)   # O(N)
        return (i - 1) * (j - 1)

    def maxProduct2(self, nums):
        # O(nlogn) run, O(n) space
        i, j = sorted(nums)[-2:]
        return (i - 1) * (j - 1)
