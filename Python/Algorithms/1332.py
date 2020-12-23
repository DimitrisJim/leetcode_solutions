class Solution:
    def removePalindromeSub(self, s: str) -> int:
        if not s:
            return 0
        # check if full string is palindrome.
        l = len(s)
        first_half = s[:l//2]
        second_half = s[l//2 + (1 if l % 2 else 0):]
        if first_half == second_half[::-1]:
            return 1

        # do we have both a's and b's or only one kind?
        return len(set(s))
