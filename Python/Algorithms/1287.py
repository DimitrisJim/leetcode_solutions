from math import ceil

class Solution:
    def findSpecialInteger(self, arr):
        length = len(arr)
        threshold, count = ceil(length * 0.25), 1
        for i in range(1, length):
            if arr[i-1] == arr[i]:
                count = count + 1
                if count > threshold:
                    return arr[i]
            else:
                count = 1
        return arr[0]
