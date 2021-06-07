class Solution:
    def reverseVowels(self, s: str) -> str:
        start, end = 0, len(s) - 1
        vowels = {*"aeiouAEIOU"}
        l = list(s)
        while start < end:
            while end > start and l[end] not in vowels:
                end -= 1
            while start < end and l[start] not in vowels:
                start += 1

            l[end], l[start] = l[start], l[end]
            start += 1
            end -= 1
        return "".join(l)
