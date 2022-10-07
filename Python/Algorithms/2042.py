class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        prev, next_ = 0, 0
        start, end = 0, len(s)
        while start < end:
            digits = []
            while start < end and s[start].isdigit():
                digits.append(s[start])
                start += 1
            if digits:
                next_ = int("".join(digits))
                if next_ <= prev:
                    return False
                prev = next_
            start += 1
        return True