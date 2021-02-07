class Solution:
    def check(self, nums: List[int]) -> bool:
        start = nums[0]
        for i in range(1, len(nums)):
            # iterate until you find possible point of rotation.
            if nums[i-1] > nums[i]:
                # then go through the rest of the elements and
                # check that they are in correct order *and*
                # that they are smaller than start (which is
                # equal to nums[0]).
                for i in range(i+1, len(nums)):
                    if nums[i] > start or nums[i-1] > nums[i]:
                        return False
        return True
