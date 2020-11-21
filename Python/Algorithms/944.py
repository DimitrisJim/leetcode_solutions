class Solution:
    def minDeletionSize(self, A):
        # basically an is_sorted query for every column.
        # set all to '1' to signal, initially, everything 
        # is sorted.
        indices = {*range(len(A[0]))}

        # Go through rows and find unsorted columns
        for i in range(len(A)-1):
            row_a, row_b = A[i], A[i+1]
            # only iterate through valid indexes.
            for idx in [*indices]:
                if row_b[idx] < row_a[idx]:
                    indices.remove(idx)

        # return number of zeros in indices
        return len(A[0]) - len(indices)
