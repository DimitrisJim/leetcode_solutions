## O(N**2), this isn't such a bad a solution but running it shows I'm missing
# something. Might just need to check solutions.

class Solution:
    def countTriples(self, n):
        count = 0
        sqrt_, ii = sqrt, float.is_integer
        for i in range(3, n - 1):
            si = i ** 2
            for j in range(i+1, n):
                # c must be integer (perfect square)
                m = sqrt_(si + j ** 2)
                # j only increases, cannot find m > n.
                if m > n:
                    if j == i + 1:
                        return count << 1
                    break
                # we know m <= n.
                if ii(m):
                    count += 1
        return count << 1
