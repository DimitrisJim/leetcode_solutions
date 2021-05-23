class Solution:
    def searchMatrix(self, matrix, target):
        n, m, j = len(matrix) - 1, len(matrix[0]), 0
        while n >= 0 and j < m:
            value = matrix[n][j]
            if value == target:
                return True
            if value > target:
                n -= 1
            else:
                j += 1
        return False
