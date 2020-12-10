from collections import deque


class Solution:
    def decrypt(self, code, k):
        # easy case
        len_ = len(code)
        if k == 0:
            return [0] * len_
        if k > 0:
            d = deque(code)
            ramount = -1
            d.rotate(ramount)
        else:
            d = deque(reversed(code))
            ramount = 1
        rng, sum_, rot = range(k if k > 0 else -k), sum, d.rotate  
        for i in range(len_):
            code[i] = sum_([d[k] for k in rng])
            rot(ramount)
        return code
