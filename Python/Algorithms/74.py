class Solution:
    def searchMatrix(self, matrix, target: int) -> bool:
        # Run a binary search per row, O(nlogn).
        rowlen = len(matrix[0])
        for row in matrix:
            if target > row[-1]:
                continue
            i = bisect_left(row, target)
            if i < rowlen and row[i] == target:
                return True
        return False
