class Solution:
    def countAsterisks(self, s: str) -> int:
        # True when we encounter first '|' false when encounter second.
        count, flag = 0, False
        for char in s:
            if char == '|':
                flag = not flag
                continue
            if char == '*' and not flag:
                count += 1
        return count