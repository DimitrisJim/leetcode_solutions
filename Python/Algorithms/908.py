class Solution:
    def smallestRangeI(self, A, K):
        min_ = max_ = A[0]
        for i in A:
            if i > max_:
                max_ = i
            if i < min_:
                min_ = i
        diff = max_ - K - min_
        if -K < diff < K:
            return 0
        return diff + (-K if diff > 0 else K)
