class Solution:
    alpha = {*ascii_letters}
    
    def reverseOnlyLetters(self, S):
        alpha = self.alpha
        start, end = 0, len(S) - 1
        S = list(S)
        while start < end:
            while S[start] not in alpha:
                if start == end:
                    return "".join(S)
                start = start + 1
            while S[end] not in alpha:
                if start == end:
                    return "".join(S)
                end = end - 1
            S[start], S[end] = S[end], S[start]
            start, end = start + 1, end - 1
        return "".join(S)
