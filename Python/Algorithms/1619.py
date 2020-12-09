class Solution:
    def trimMean(self, arr):
        trim = int(len(arr) * 0.05);
        return sum(sorted(arr)[trim:-trim]) / (len(arr) - 2 * trim)
