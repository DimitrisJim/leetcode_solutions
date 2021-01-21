class Solution:
    def missingNumber(self, nums):
        # n disting numbers in [0, n] can use
        # xor trick.

        # One distinct number, so, we can also xor in
        # all the numbers in the range and after xoring
        # with the numbers in nums, the unique element will
        # be the only one left (since it doesn't exist in
        # nums in order for it to be xore'd out.)
        missing = i = 0
        for num in nums:
            i = i + 1
            missing ^= i ^ num
        return missing
