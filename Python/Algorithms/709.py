class Solution:
    def toLowerCase(self, s: str) -> str:
        # weirdly enough, this is timed faster than
        # str.lower(s) or s.lower()
        return "".join(map(str.lower, s))
