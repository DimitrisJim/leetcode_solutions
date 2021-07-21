class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums) - 1
        i = length
        # find shortest non-decreasing sequence, e.g
        # [1, 2, 5, 4, 3] => [2, 5, 4, 3]
        while i > 0:
            if nums[i - 1] < nums[i]:
                break
            i -= 1
        if i > 0:
            # find smalest value in nums[i:] that is
            # larger than start of sequence. (i - 1)
            j = length
            while j >= i:
                if nums[j] > nums[i - 1]:
                    break
                j -= 1
            # switch positions and reverse values after it.
            nums[i - 1], nums[j] = nums[j], nums[i - 1]
            nums[i:] = nums[-1:i - 1:-1]
        # i == 0 means we have the highest possible order. (descending)
        # so just reverse.
        else:
            nums[::] = nums[::-1]
