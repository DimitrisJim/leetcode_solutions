class Solution:
    def countNegatives(self, grid):
        # get n and m
        n, m = len(grid), len(grid[0])
        if grid[0][0] < 0:
            return n * m
        # Traverse if one of n or m is 1.
        if m == 1:
            positives = 0
            while positives < n and grid[positives][0] >= 0:
                positives += 1
            return n - positives
        if n == 1:
            positives = 0
            while positives < m and grid[0][positives] >= 0:
                positives += 1
            return m - positives

        # Set up two points, bottom_left and top_right,
        # we count until we converge.
        bottom_left = [n-1, 0]
        top_right = [0, m-1]
        negatives = 0
        while bottom_left != top_right:
            # unpack coordinates
            bli, blj = bottom_left
            tri, trj = top_right

            # Further edge cases:
            # a) We've met on a row
            if bli == tri:
                # need to traverse
                while blj <= trj:
                    if grid[bli][blj] < 0:
                        negatives += 1
                    blj += 1
                return negatives
            # b) We've met on a column
            if trj == blj:
                # need to traverse
                while tri <= bli:
                    if grid[tri][trj] < 0:
                        negatives += 1
                    tri += 1
                return negatives

            # 1) Bottom_left is negative
            if grid[bli][blj] < 0:
                # if top right is also negative, count both
                # row and cols and move up for bottom_left
                # and left for top_right
                if grid[tri][trj] < 0:
                    negatives += (bli - tri) + (trj - blj) + 1
                    # move both points to next row/col
                    top_right[1] = top_right[1] - 1
                    bottom_left[0] = bottom_left[0] - 1
                # else, move top_right downwards trying to
                # find a negative.
                else:
                    top_right[0] = top_right[0] + 1
            # Bottom left isn't negative.
            else:
                # if top right is also positive, move it downwards
                if grid[tri][trj] >= 0:
                    top_right[0] = top_right[0] + 1
                # and move bottom_left right.
                bottom_left[1] = bottom_left[1] + 1
        # if we converge, count the point of convergence if
        # it is negative.
        i, j = bottom_left
        return negatives + (1 if grid[i][j] < 0 else 0)
