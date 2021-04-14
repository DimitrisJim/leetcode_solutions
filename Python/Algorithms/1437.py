class Solution:
    def kLengthApart(self, nums, k: int) -> bool:
        # find first index of 1 (on error, return early.)
        try:
            first_one = nums.index(1)
        except ValueError:
            return True
        # Scan along counting distances.
        diff = k
        for i in range(first_one + 1, len(nums)):
            if nums[i]:
                if diff > 0:
                    return False
                diff = k
            else:
                diff -= 1
        return True