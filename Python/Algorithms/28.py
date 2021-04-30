class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # return early for edge cases.
        if not needle:
            return 0
        lenh, lenn = len(haystack), len(needle)
        if lenh < lenn:
            return -1

        # make range for needle, keep res, make diff index needs to be
        # smaller than in order to check for a match.
        rngn, res, diff = range(lenn), -1, lenh - lenn
        for index in range(lenh):
            if index <= diff:
                if all(needle[i] == haystack[index+i] for i in rngn):
                    res = index
                    break
        return res
