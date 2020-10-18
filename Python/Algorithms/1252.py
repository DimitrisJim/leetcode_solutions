class Solution:
    """ Don't use dictionary, use number as bitset.

    Weirdly enough, doesn't impact memory measurements *at all*.
    """
    def oddCells(self, n, m, indices):
        # handle case 1 x 1
        if m == n == 1:
            return 0
        # hold odd columns & rows
        rows = cols = 0

        for ni, mi in indices:
            # remove if even, == 1 if not present.
            rows = rows ^ (2 ** ni)
            cols = cols ^ (2 ** mi)
        # count number of bits set in rows & cols.
        lrows = lcols = 0
        while rows:
            lrows = lrows + (rows & 1)
            rows = rows >> 1
        while cols:
            lcols = lcols + (cols & 1)
            cols = cols >> 1

        # cases 2 x 1 and 1 x 2:
        if (n == 1 and m == 2) or (n == 2 and m == 1):
            return lrows if lrows >= lcols else lcols
        # handle case 2 x 2
        if n == m == 2:
            if lrows == lcols == 2 or lrows == lcols == 0:
                return 0
            if {lrows, lcols} == {2, 0}:
                return 4
            return 2
        # yet another edge case
        if n == 2 or m == 2:
            return ((m - lcols) * lrows) if n == 2 else ((n - lrows) * lcols)
        # Finally, can add things up:
        return (m - lcols) * lrows + (n - lrows) * lcols
    
    def _oddCells(self, n: int, m: int, indices):
        """ Original solution. Keep # of odd cols/rows in a dictionary. """
        # handle case 1 x 1
        if m == n == 1:
            return 0
        # hold odd columns & rows
        rows = {}
        cols = {}
        rp, cp = rows.pop, cols.pop
        for _ in indices:
            ni, mi = _
            # remove if even, == 1 if not present.
            if ni in rows:
                rp(ni)
            else:
                rows[ni] = 1
            if mi in cols:
                cp(mi)
            else:
                cols[mi] = 1
        lrows, lcols = len(rows), len(cols)
        # cases 2 x 1 and 1 x 2:
        if {n, m} == {1, 2}:
            return lrows if lrows >= lcols else lcols
        # handle case 2 x 2
        if n == m == 2:
            if lrows == lcols == 2 or lrows == lcols == 0:
                return 0
            if {lrows, lcols} == {2, 0}:
                return 4
            return 2

        # yet another edge case
        if n == 2 or m == 2:
            return ((m - lcols) * lrows) if n == 2 else ((n - lrows) * lcols)
        # Finally, can things up:
        return (m - lcols) * lrows + (n - lrows) * lcols
