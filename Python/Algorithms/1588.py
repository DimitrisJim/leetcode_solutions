from itertools import starmap


class Solution:
    def mults(self, l):
        # knock out special cases first.
        if l < 3:
            return [1] * l
        if l == 3:
            return [2] * l
        # build list of odd numbers (signifying groups) and the 
        # max amount of time they can occur in a list with length l.
        odds_pairs = [(o, (1 + (l - o))) for o in range(1, l + 1, 2)]
        
        # first element gets 1 from all groups.
        res = [len(odds_pairs)]  # for first element
        
        mid = ((l // 2) + 1) if l % 2 else l // 2
        for idx in range(2, mid + 1):
            sum_ = 0
            # the crux of the logic. not really easy to explain 
            # in comments so I'll try to explain in README.md
            for odd, occur in odds_pairs:
                if idx < odd and occur > idx:
                    sum_ += idx
                else:
                    if odd <= occur:
                        sum_ += odd
                    else:
                        sum_ += occur
            res.append(sum_)
            
        # for odd lists, elements are mirrored until 
        # mid - 2, append them (in reverse order).
        if l % 2:
            for i in range(len(res) - 2, - 1, -1):
                res.append(res[i])
        # for even lists, elements are mirrored until 
        # mid - 1, append them (in reverse order)
        else:
            for i in range(len(res) - 1, -1, - 1):
                res.append(res[i])
        # could yield all instead of returning explicit list but meh
        return res
    
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        multipliers = self.mults(len(arr))
        multfunc = int.__mul__
        return sum(starmap(multfunc, zip(arr, multipliers)))
