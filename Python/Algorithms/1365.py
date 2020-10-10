class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        nl = len(nums) - 1
        # sort and return values enumerated
        # we use the enumeration to calculate the
        # items to the right of the sorted value in the
        # sorted list. O(nlogn)
        enumeration = enumerate(sorted(nums, reverse=True))
        counts = {v: nl - ind for ind, v in enumeration}
        # build counts O(n)
        return [counts[v] for v in nums]
