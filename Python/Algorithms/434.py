class Solution:
    def countSegments(self, s: str) -> int:
        return len([*filter(None, s.split())])
