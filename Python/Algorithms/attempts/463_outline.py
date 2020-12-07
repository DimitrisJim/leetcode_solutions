class Solution:

    @staticmethod
    def init_perimeter(grid, r, x, y):
        if y >= 0:
            # look down for possible block
            if x + 1 < r:
                if grid[x + 1][y]:
                    return 2
        return 1


    def find_start(self, grid, rows, cols):
        """
        Find first piece of land. Return coordinates right
        before it.
        """
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    # right 'above' first piece of land
                    # we find.
                    point = (i, j-1)
                    return (point, self.init_perimeter(grid, rows, *point))


    def islandPerimeter(self, grid):
        # start denotes point of first land.
        cols, rows = len(grid[0]), len(grid)
        start, init_perim = self.find_start(grid, rows, cols)
        next_points = lambda x, y: ([
                (x-1, y),    # down
                (x+1, y),    # up
                (x, y-1),    # left
                (x, y+1),    # right
                (x-1, y-1),  # up and left  (diagonally)
                (x-1, y+1),  # up and right (diagonally)
                (x+1, y-1),  # down and left    (diagonally)
                (x+1, y+1),  # down and right   (diagonally)
            ])
        # when going to next point only look down, up, right, left
        look = lambda x, y, r, c: ([
            i for i in ((x-1, y), (x+1, y), (x, y-1), (x, y+1))
             if 0 <= i[0] < r and 0 <= i[1] < c
        ])
        # Keep track of what we've seen and what's pending
        perimeter, visited, pending = 0, set(), [(start, init_perim)]
        while pending:
            point, sides = pending.pop()
            if point in visited:
                continue
            visited.add(point)
            x, y = point
            perimeter += sides

            # go through non-visited points
            # visit point with largest sides value first.
            max_sides = 0
            for nx, ny in (i for i in next_points(x, y) if i not in visited):
                # Don't go to land-cells.
                if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny]:
                    continue

                directions = look(nx, ny, rows, cols)
                sides = sum(1 for (i, j) in directions if grid[i][j] and (i, j) not in visited)
                if sides > max_sides:
                    max_sides = sides
                    point = (nx, ny)
                if sides >= 1:
                    # keep around for later.
                    pending.append(((nx, ny), sides))
            # final one appended, first one seen when pop'ing.
            if max_sides:
                pending.append((point, max_sides))

        return perimeter
