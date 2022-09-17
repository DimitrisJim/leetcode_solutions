class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        c1, r1, c2, r2 = s[0], int(s[1]), s[3], int(s[4])
        
        result = []
        # range through c1 - c2 and then through r1 - r2 and build cells.
        for i in range(ord(c1), ord(c2) + 1):
            for j in range(r1, r2+1):
                result.append(f"{chr(i)}{j}")
        return result