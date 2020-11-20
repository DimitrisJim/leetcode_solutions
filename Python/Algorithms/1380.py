class Solution:
    def luckyNumbers(self, matrix):
        # initialize maxes to first row and mins to first row min
        maxes = [*matrix[0]]
        mins = {min(maxes)}
        enumerate_, add = enumerate, mins.add
        # go through the rows
        for i in range(1, len(matrix)):
            min_ = matrix[i][0]
            # and add to mins and update max per row.
            for i, el in enumerate_(matrix[i]):
                if el < min_:
                    min_ = el
                if maxes[i] < el:
                    maxes[i] = el
            add(min_)
        # lucky numbers will be intersection.
        # or 
        # return list(filter(mins.__contains__, maxes))
        return mins & set(maxes)
