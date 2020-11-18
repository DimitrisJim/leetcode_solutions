class Solution:
    def peakIndexInMountainArray(self, arr):
        i, j = 0, len(arr)
        m = (j + i) // 2
        while True:
            mid = arr[m]
            # increasing, go right
            if arr[m + 1] > mid:
                i = m + 1 
            # We're decreasing, go left.
            elif arr[m-1] > mid:
                j = m - 1
            else:
                return m
            m = (j + i) // 2
