class Solution:

    def canFormArray(self, arr, pieces):
        els = set(arr)
        len_ = len

        for sub in pieces:
            # Sub-lists with length one can be re-ordered freely.
            if len_(sub) == 1:
                if sub[0] not in els:
                    return False
            # for larger ones, we need to check they are contiguous.
            else:
                if sub[0] not in els:
                    return False
                idx = arr.index(sub[0])
                for j in range(1, len(sub)):
                    idx_ = idx + j
                    if idx_ >= len_(arr) or arr[idx_] != sub[j]:
                        return False 
        return True
