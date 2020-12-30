class Solution:
    def sumEvenAfterQueries(self, A, queries):
        # keep around total sum, we update (if we find evens) on
        # each iteration.
        evenSum = sum(i for i in A if i & 1 == 0)
        for idx, (value, index) in enumerate(queries):
            old_value = A[index]
            new_value = value + old_value
            # add new value if it is even.
            if not new_value & 1:
                evenSum = evenSum + new_value
            # remove old value if it was even.
            if not old_value & 1:
                evenSum = evenSum - old_value
            A[index] = new_value
            # reuse it
            queries[idx] = evenSum
        return queries
