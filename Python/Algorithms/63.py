class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # cases where we can't move from start/to end because it's blocked.
        if obstacleGrid[0][0] or obstacleGrid[-1][-1]:
            return 0

        # Build m x n matrix to hold paths.
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        mat = [[0] * n for _ in range(m)]
        mat[0][0] = 1

        for r in range(m):
            for c in range(n):
                # If this path is blocked, move on.
                if obstacleGrid[r][c]:
                    continue

                # if not, check if we had an obstacle on top.
                if r and obstacleGrid[r-1][c] == 0:
                    mat[r][c] = mat[r-1][c]
                # or to our left.
                if c and obstacleGrid[r][c-1] == 0:
                    mat[r][c] += mat[r][c-1]

        # end will hold total number of paths.
        return mat[-1][-1]
