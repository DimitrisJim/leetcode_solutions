class Solution:
    def allCellsDistOrder(self, R, C, r, c):
        # place pair first.
        result = [[r, c]]
        gen = ((i,j) for j in range(max(C-c,c)+1) for i in range(max(R-r,r)+1))
        next(gen)
        indices = iter(sorted(gen, key=sum))
        app = result.append
        for i, j in indices:
            # don't recalculate.
            rpi, rmi, cpj, cmj = (r + i, r - i, c + j, c - j)
            if rmi >= 0:
                if cmj >= 0:
                    app([rmi, cmj])
                if j and cpj < C:
                    app([rmi, cpj])
            if rpi < R and i:
                if cpj < C:
                    app([rpi, cpj])
                if j and cmj >= 0:
                    app([rpi, cmj])
        return result
