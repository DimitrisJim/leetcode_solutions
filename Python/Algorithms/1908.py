class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        removed, i, end = False, 0, len(nums) - 1
        while i < end:
            a, b = nums[i], nums[i+1]
            if a >= b:
                # if we've removed before, return.
                if removed:
                    return False
                # Need to check neighbours of a, b.
                # if b <= than neighbour of a, b is the
                # odd one out and should be removed.
                if i > 0 and b <= nums[i-1]:
                    # but if a is larger than neighbour of
                    # b, there's nothing we can do.
                    if i + 2 < len(nums) and a >= nums[i+2]:
                        return False
                    i += 1
                removed = not removed
            i += 1
        return True
