class Solution:
    def diagonalSum(self, mat):
        mat_len = len(mat)
        # Remove middle element if mat has odd length
        sum_ = -mat[mat_len >> 1][mat_len >> 1] if mat_len % 2 else 0
        # Count diagonals.
        for i in range(0, mat_len):
            sum_ = sum_ + mat[i][i] + mat[i][mat_len - i - 1]
        return sum_
