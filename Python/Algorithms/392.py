class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        start_index = 0
        for c in s:
            start_index = t.find(c, start_index)
            if start_index == -1:
                return False
            else:
                start_index += 1
        return True
