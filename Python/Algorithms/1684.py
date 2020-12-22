class Solution:
    def countConsistentStrings(self, allowed: str, words):
        allowed = {*allowed}
        return sum({*w} <= allowed for w in words)
