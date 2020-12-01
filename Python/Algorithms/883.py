class Solution:

    def projectionArea(self, grid):
        enum = enumerate
        # view_z is sum of len of each cell.
        # view_x is max slot of each row.
        # view_y is max of each column.
        view_y = grid[0]  # keep track of maxes
        view_z, view_x = sum(_ != 0 for _ in view_y), max(view_y)
        for j in range(1, len(grid)):
            count = max_v = 0
            for i, vc in enum(grid[j]):
                if vc:
                    # for view_z
                    count = count + 1
                    # for view_x
                    if vc > max_v:
                        max_v = vc
                    # for view_y
                    # make sure we haven't reached end of view_y (i.e cvy != -1)
                    if vc >= view_y[i]:
                        view_y[i] = vc
            # add to counters.
            view_z = view_z + count
            view_x = view_x + max_v
        return view_z + view_x + sum(view_y)
