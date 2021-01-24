class SubrectangleQueries:
    def __init__(self, rectangle):
        self.rect = rectangle

    def updateSubrectangle(self, row1, col1, row2, col2, newValue):
        rect = self.rect
        rows, cols = range(row1, row2 + 1), range(col1, col2 + 1)
        for i in rows:
            r = rect[i]
            for j in cols:
                r[j] = newValue

    def getValue(self, row, col):
        return self.rect[row][col]
