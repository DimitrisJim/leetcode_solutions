class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        end = len(s) - 1
        while s[end] == ' ':
            end -= 1
            if end == -1:
                return 0
        # reached end of last word.
        count = 0
        while s[end] != ' ':
            end -= 1
            count += 1
            if end == -1:
                break
        return count
