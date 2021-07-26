class Solution:
    def getLucky(self, s: str, k: int) -> int:
        nums = []
        for c in s:
            v = ord(c) - 96
            if v < 10:
                nums.append(v)
            else:
                nums.extend(divmod(v, 10))
        # 'return sum(nums)' counts as final transformation
        # so k should be > 1.
        while k > 1 and len(nums) > 1:
            nums = [int(i) for i in str(sum(nums))]
            k -= 1
        return sum(nums)
