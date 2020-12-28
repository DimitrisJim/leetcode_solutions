from collections import deque
from itertools import chain


class Solution:
    def shiftGrid(self, grid, k):
        rows, cols = range(len(grid)), range(len(grid[0]))
        d = deque(chain.from_iterable(grid))
        d.rotate(k)
        pop = d.popleft
        for i in rows:
            for j in cols:
                grid[i][j] = pop()
        return grid
