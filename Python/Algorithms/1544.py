class Solution:
    def makeGood(self, s):
        res, i, end = [], 0, len(s) - 1
        while i < end:
            v = s[i]
            if abs(ord(v) - ord(s[i + 1])) == 32:
                i = i + 2
                while (i <= end) and res:
                    # After removing a pair, we need to check if the
                    # next character in s might be making a bad pair
                    # with the pair last added to res. If so, remove it.
                    if abs(ord(s[i]) - ord(res[-1])) == 32:
                        res.pop()
                        i = i + 1
                    # and break when we can't remove (or while clause bails)
                    else:
                        break
            else:
                res.append(v)
                i = i + 1
        # We must go until < end, so we need to take
        # into account a letter that might be hanging
        # at the end (if it isn't part of a pair.)
        if i == end:
            res.append(s[-1])
        return "".join(res)
