from collections import Counter


class Solution:
    def longestPalindrome(self, s: str) -> int:
        # create a dictionary for characters of a given string
        length, one = 0, 0
        for count in Counter(s).values():
            if count & 1:
                one = 1
                length -= 1
            length += count
        return length + one
