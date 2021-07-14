class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        """ Via tabulation. """
        length = target + 1
        a = [0] * length
        a[0] = 1
        for i in range(length):
            if a[i] == 0:
                continue
            for v in nums:
                new_pos = i + v
                if new_pos < length:
                    # add to value a[i + v] the # of times we can to a[i]
                    a[new_pos] += a[i]
        return a[-1]

    def _combinationSum4(self, nums: List[int], target: int) -> int:
        """ Via recursion. """
        cache = {}

        def canSum(target):
            if target in cache:
                return cache[target]
            if target == 0:
                return 1
            result = 0
            for element in nums:
                t = target - element
                if t >= 0:
                    res = canSum(t)
                    result += res
            cache[target] = result
            return result
        canSum(target)
        return cache[target]
