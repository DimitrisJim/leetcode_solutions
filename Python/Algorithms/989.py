class Solution:
    def addToArrayForm(self, A, K):
        i, dm = len(A) - 1, divmod

        # go through and try and add number.
        while i >= 0 and K:
            # Add rightmost digit.
            K, r = dm(K, 10)
            if A[i] + r > 9:
                A[i] = (r + A[i]) % 10
                K = K + 1
            else:
                A[i] += r
            i = i - 1

        # Special case, we reached end and still
        # have a value to add.
        if i == -1 and A[0] == 0 or K:
            tmp = []
            while K:
                K, r = dm(K, 10)
                tmp.append(r)
            return [*reversed(tmp), *A]
        return A
