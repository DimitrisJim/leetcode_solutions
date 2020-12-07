ass Solution:
    def get_start(self, grid, rows, cols):
        # start denotes point before first land.
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]:
                    return (i, j)


    def islandPerimeter(self, grid: List[List[int]]) -> int:
        # start denotes point before first land.
        cols, rows = len(grid[0]), len(grid)
        start = self.get_start(grid, rows, cols)

        # Until we circle back to start, move around land.
        perimeter = 0
        visited, to_visit = set(), [start]
        pop, app, add = to_visit.pop, to_visit.append, visited.add
        while to_visit:
            cell = pop()
            if cell in visited:
                continue
            add(cell)
            x, y = cell

            # look left and right
            ny = y - 1
            if 0 <= ny and grid[x][ny]:
                t = x, ny
                if t not in visited:
                    app(t)
            else:
                perimeter = perimeter + 1
            ny = y + 1
            if ny < cols and grid[x][ny]:
                t = (x, ny)
                if t not in visited:
                    app(t)
            else:
                perimeter = perimeter + 1

            # look up and down.
            nx = x - 1
            if 0 <= nx and grid[nx][y]:
                t = (nx, y)
                if t not in visited:
                    app(t)
            else:
                perimeter = perimeter + 1
            nx = x + 1
            if nx < rows and grid[nx][y]:
                t = (nx, y)
                if t not in visited:
                    app(t)
            else:
                perimeter = perimeter + 1
        return perimeter
