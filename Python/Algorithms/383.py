from collections import Counter


class Solution:
    def canConstruct(self, ransomNote, magazine):
        return not Counter(ransomNote) - Counter(magazine)
