class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        seq_len = max_len = 0
        prev = float('-inf')
        for i in nums:
            if i > prev:
                seq_len += 1
                if seq_len > max_len:
                    max_len = seq_len
            else:
                seq_len = 1
            prev = i
        return max_len
