class Solution:
    def findLucky(self, arr):
        c, largest = Counter(arr), -1
        for k, v in c.most_common():
            if k == v:
                largest = k
                break
        return largest
