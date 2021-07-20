class Solution:
    def longestCommonPrefix(self, strs):
        it = iter(strs)
        prefix = next(it)
        for s in it:
            # reduce prefix to the common prefix between
            # it and s.
            i, end = 0, min(len(prefix), len(s))
            while i < end and s[i] == prefix[i]:
                i += 1
            prefix = prefix[:i]
            if not prefix:
                return ""
        return prefix
