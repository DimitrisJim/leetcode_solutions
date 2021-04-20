class Solution:
    def searchInsert(self, nums, target: int) -> int:
        """ Start points to position in list for which all
        elements with index smaller than start have a value smaller
        than target and all elements with index larger than it
        have a value >= to target.

        When finished, start will either point to target or the leftmost
        position in which to insert it.
        """
        start, end = 0, len(nums)
        while start < end:
            mid = (start + end) // 2
            if nums[mid] < target:
                start = mid + 1
            else:
                end = mid
        return start
