class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        for i in range(n):
            for j in range(n):
                # check diagonals
                if j == i or j == n - i - 1:
                    if grid[i][j] == 0:
                        return False
                elif grid[i][j]:
                    return False
        return True