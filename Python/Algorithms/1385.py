class Solution:
    def findTheDistanceValue(self, arr1, arr2, d):
        count = 0
        for i in arr1:
            top, bottom = i + d, i - d
            for j in arr2:
                if top >= j and j >= bottom:
                    break
            else:
                count = count + 1
        return count
