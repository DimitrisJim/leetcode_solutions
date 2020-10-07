class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        # O(N) worse case.
        m = max(candies)
        return [i + extraCandies >= m for i in candies]
