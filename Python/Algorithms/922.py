class Solution:
    def sortArrayByParityII_inplace(self, A):
        for idx, i in enumerate(A):
            type_ = idx % 2
            if not type_ == i % 2:
                for t in range(idx + 1, len(A)):
                    if (A[t] % 2) == type_:
                        A[idx], A[t] = A[t], A[idx]
                        break
        return A

    def sortArrayByParityII(self, A):
        # build a list of the same size.
        res = [0 for _ in A]
        oddp, evenp = 1, 0
        # add according to oddp(osition) and evenp(osition)
        for i in A:
            if i % 2:
                res[oddp] = i
                oddp += 2
            else:
                res[evenp] = i
                evenp += 2
        return res
