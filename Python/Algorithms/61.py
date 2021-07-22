class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        mat = [[0] * n for _ in range(m)]
        mat[0] = [1] * n
        for r in range(1, m):
            for c in range(n):
                mat[r][c] = mat[r-1][c]
                if c > 0:
                    mat[r][c] += mat[r][c-1]
        return mat[-1][-1]
