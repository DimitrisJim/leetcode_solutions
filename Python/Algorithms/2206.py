class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        s = set()
        for _ in nums:
            if _ in s:
                s.remove(_)
            else:
                s.add(_)
        return len(s) == 0