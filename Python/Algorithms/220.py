class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        snum, length = sorted(enumerate(nums), key=itemgetter(1)), len(nums)
        for i in range(length):
            j = i + 1
            while j < length and snum[j][1] - snum[i][1] <= t:
                if abs(snum[i][0] - snum[j][0]) <= k:
                    return True
                j = j + 1
        return False
