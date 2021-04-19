# The isBadVersion API is already defined for you.
# @param version, an integer
# @return an integer
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        start, end = 0, n
        while end - start != 1:
            mid = (start + end) // 2
            if isBadVersion(mid):
                # set as end.
                end = mid
            else:
                start = mid
        return end
