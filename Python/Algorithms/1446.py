class Solution:
    def maxPower(self, s: str) -> int:
        max_subseq, count = 0, 0
        current = s[0]
        for n in s:
            if n == current:
                count = count + 1
                if count > max_subseq:
                    max_subseq = count
            else:
                count = 1
                current = n
        return max_subseq
