class Solution:

    def countGoodTriplets(self, arr, a, b, c):
        count = 0
        abs_ = abs        # silly optimization trick.
        range_ = range    # silly optimization trick.
        array_len = len(arr)
        for i in range_(array_len):
            ai = arr[i]
            for j in range_(i+1, array_len):
                aj = arr[j]
                # bail early if we can.
                if (a >= abs_(ai - aj)):
                    for k in range_(j+1, array_len):
                        ak = arr[k]
                        # now we can check the rest of the inequalities.
                        if (b >= abs_(aj - ak)) and \
                           (c >= abs_(ai - ak)):
                            count = count + 1
        return count
