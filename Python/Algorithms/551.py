class Solution:
    def checkRecord(self, s: str) -> bool:
        consecutive = 0
        a_count = 0
        for i in s:
            if i == 'L':
                consecutive += 1
                if consecutive == 3:
                    return False
                continue
            if i == 'A':
                a_count += 1
                if a_count > 1:
                    return False
            consecutive = 0
        return True
