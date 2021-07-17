class Solution:
    def countTriples(self, n):
        # precompute all powers from
        pows = [x ** 2 for x in range(n)]
        count = 0
        for i in range(3, n - 1):
            si = pows[i]
            for j in range(i+1, n):
                # c must be integer (perfect square)
                m = sqrt(si + pows[j])
                # j only increases, cannot find m > n.
                if m > n:
                    # means m was > n during first iteration,
                    # i.e for consequent iterations it will
                    # always be > n.
                    if j == i + 1:
                        return count * 2
                    break
                # we know m <= n.
                if m.is_integer():
                    count += 1
        return count * 2
