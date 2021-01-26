class Solution:
    def maxIncreaseKeepingSkyline(self, grid):
        min_, max_ = min, max
        rows, cols = len(grid), len(grid[0])
        max_cols = []

        max_increase = 0
        for i in range(rows):
            r = grid[i]
            # find max for row.
            max_row = max(r)
            for j in range(cols):
                # find max for column.
                if j == len(max_cols):
                    max_cols.append(max_(grid[i][j] for i in range(rows)))

                diff = min_(max_row, max_cols[j]) - grid[i][j]
                if diff > 0:
                    max_increase = max_increase + diff
        return max_increase
