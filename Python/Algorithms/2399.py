class Solution:
    def checkDistances(self, s: str, distance: List[int]) -> bool:
        length = len(s)
        for idx, c in enumerate(s):
            pos = ord(c) - 97
            
            # Mark distance as seen.
            dist = distance[pos] + 1
            if dist == -1:
                continue
            else:
                distance[pos] = -2
            dist += idx
            if dist < length and s[dist] == c:
                continue
            return False
        return True