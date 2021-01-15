class Solution:
    def twoSum(self, numbers, target):
        i, j = 0, len(numbers) - 1
        while i < j:
            ts = numbers[i] + numbers[j]
            if ts == target:
                break
            elif ts > target:
                j = j - 1
            else:
                i = i + 1
        return [i+1, j+1]
