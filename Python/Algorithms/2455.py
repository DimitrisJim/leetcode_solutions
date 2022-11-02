class Solution:
    def averageValue(self, nums: List[int]) -> int:
        sum_, count = 0, 0
        for i in nums:
            if i & 1 == 0 and i % 3 == 0:
                sum_ += i
                count += 1
        return sum_ // count if count else 0