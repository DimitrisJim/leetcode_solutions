class Solution:
    def replaceElements(self, arr):
        max_, arr[-1] = arr[-1], - 1
        for i in range(len(arr) - 2, -1, -1):
            val, arr[i] = arr[i], max_
            if val > max_:
                max_ = val
        return arr
