class Solution:
    def diagonalSort(self, mat):
        rows, cols = len(mat) - 1, len(mat[0]) - 1
        # start from bottom-left.
        r, c = rows, 0
        # grabs diagonals in diag, sorts them, and places
        # them back.
        diag = []
        # stop when we reach top right point.
        while r != 0 or c != cols:
            i, j = r, c
            while i <= rows and j <= cols:
                diag.append(mat[i][j])
                i, j = i + 1, j + 1
            diag.sort(reverse=True)
            # reset and go through again, setting new values
            i, j = r, c
            while i <= rows and j <= cols:
                mat[i][j] = diag.pop()
                i, j = i + 1, j + 1
            # note: first decrement column tracker.
            if not r:
                c = c + 1
            if r:
                r = r - 1
        return mat
