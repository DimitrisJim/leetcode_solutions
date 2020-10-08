class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        # sort initially.
        nums.sort()
        # 1 + 2 + 3 + ... + n
        sn = lambda n: (n * (n + 1)) // 2
        num_of_pairs = num = 0
        for i in range(1, len(nums)):
            # found a pair
            if nums[i] == nums[i - 1]:
                num += 1
            # bumped into next group.
            else:
                num_of_pairs += sn(num)
                num = 0
        # add left-overs from final group.
        num_of_pairs += sn(num)
        return num_of_pairs
