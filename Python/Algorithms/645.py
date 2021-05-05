class Solution:
    def findErrorNums(self, nums):
        dup = 0
        for i in nums:
            index = abs(i) - 1
            if nums[index] < 0:
                dup = index + 1
                # don't change index back
                continue
            nums[index] = -nums[index]

        missing = 0
        for index, i in enumerate(nums):
            if i > 0:
                missing = index + 1
                break
        return dup, missing

    def findErrorNums_(self, nums):
        n = len(nums)
        sum_to_n = (n * (n + 1)) // 2
        seen, dup, sum_err = set(), 0, 0
        for i in range(n):
            if nums[i] in seen:
                dup = nums[i]
                sum_err += sum(nums[i:])
                return dup, (sum_to_n - (sum_err - dup))
            seen.add(nums[i])
            sum_err += nums[i]
