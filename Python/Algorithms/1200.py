class Solution:
    def minimumAbsDifference(self, arr):
        abs_, min_diff, res = abs, 10**6, []
        # sort first, bring elements in increasing
        # order (so we only need to check next to)
        # find a possible min value.
        arr.sort()
        for k in range(len(arr)-1):
            i, j = arr[k+1], arr[k]
            diff = abs_(i - j)
            # if min, start collecting again.
            if diff < min_diff:
                min_diff = diff
                res = [[j, i]]
            # else, add it to result.
            elif diff == min_diff:
                res.append([j, i])
        return res
